static void emit_port_info(struct state *this, struct port *port, bool full)
{
	uint64_t old = full ? port->info.change_mask : 0;

	if (full)
		port->info.change_mask = port->info_all;
	if (port->info.change_mask) {
		uint32_t i;

		if (port->info.change_mask & SPA_PORT_CHANGE_MASK_PARAMS) {
			for (i = 0; i < port->info.n_params; i++) {
				if (port->params[i].user > 0) {
					port->params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					port->params[i].user = 0;
				}
			}
		}
		spa_node_emit_port_info(&this->hooks,
				port->direction, port->id, &port->info);
		port->info.change_mask = old;
	}
}