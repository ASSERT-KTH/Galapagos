static void emit_port_info(struct stream *d, bool full)
{
	uint32_t i;
	uint64_t old = full ? d->port_info.change_mask : 0;
	if (full)
		d->port_info.change_mask = d->port_change_mask_all;
	if (d->port_info.change_mask != 0) {
		if (d->port_info.change_mask & SPA_PORT_CHANGE_MASK_PARAMS) {
			for (i = 0; i < d->port_info.n_params; i++) {
				if (d->port_params[i].user > 0) {
					d->port_params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					d->port_params[i].user = 0;
				}
			}
		}
		spa_node_emit_port_info(&d->hooks, d->direction, 0, &d->port_info);
	}
	d->port_info.change_mask = old;
}