static void emit_port_info(struct impl *this, struct port *port, bool full)
{
	uint64_t old = full ? port->info.change_mask : 0;

	if (full)
		port->info.change_mask = port->info_all;
	if (port->info.change_mask) {
		struct spa_dict_item items[4];
		uint32_t n_items = 0;

		if (PORT_IS_DSP(this, port->direction, port->id)) {
			items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_FORMAT_DSP, "32 bit float mono audio");
			items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_AUDIO_CHANNEL, port->position);
			if (port->is_monitor)
				items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_PORT_MONITOR, "true");
			if (this->port_ignore_latency)
				items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_PORT_IGNORE_LATENCY, "true");
		} else if (PORT_IS_CONTROL(this, port->direction, port->id)) {
			items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_PORT_NAME, "control");
			items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_FORMAT_DSP, "8 bit raw midi");
		}
		port->info.props = &SPA_DICT_INIT(items, n_items);

		if (port->info.change_mask & SPA_PORT_CHANGE_MASK_PARAMS) {
			SPA_FOR_EACH_ELEMENT_VAR(port->params, p) {
				if (p->user > 0) {
					p->flags ^= SPA_PARAM_INFO_SERIAL;
					p->user = 0;
				}
			}
		}
		spa_node_emit_port_info(&this->hooks, port->direction, port->id, &port->info);
		port->info.change_mask = old;
	}
}