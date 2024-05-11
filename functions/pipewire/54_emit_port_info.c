static void emit_port_info(struct impl *this, struct port *port, bool full)
{
	uint64_t old = full ? port->info.change_mask : 0;
	if (full)
		port->info.change_mask = port->info_all;
	if (port->info.change_mask) {
		struct spa_dict_item items[1];

		items[0] = SPA_DICT_ITEM_INIT(SPA_KEY_FORMAT_DSP, "32 bit float RGBA video");
		port->info.props = &SPA_DICT_INIT(items, 1);
		spa_node_emit_port_info(&this->hooks,
				SPA_DIRECTION_OUTPUT, 0, &port->info);
		port->info.change_mask = old;
	}
}