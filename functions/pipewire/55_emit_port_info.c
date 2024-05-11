static void emit_port_info(struct filter *d, struct port *p, bool full)
{
	uint32_t i;
	uint64_t old = full ? p->info.change_mask : 0;
	if (full)
		p->info.change_mask = p->change_mask_all;
	if (p->info.change_mask != 0) {
		if (p->info.change_mask & SPA_PORT_CHANGE_MASK_PARAMS) {
			for (i = 0; i < p->info.n_params; i++) {
				if (p->params[i].user > 0) {
					p->params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					p->params[i].user = 0;
				}
			}
		}
		spa_node_emit_port_info(&d->hooks, p->direction, p->id, &p->info);
	}
	p->info.change_mask = old;
}