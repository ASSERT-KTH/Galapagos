static void emit_node_info(struct filter *d, bool full)
{
	uint32_t i;
	uint64_t old = full ? d->info.change_mask : 0;
	if (full)
		d->info.change_mask = d->change_mask_all;
	if (d->info.change_mask != 0) {
		if (d->info.change_mask & SPA_NODE_CHANGE_MASK_PARAMS) {
			for (i = 0; i < d->info.n_params; i++) {
				if (d->params[i].user > 0) {
					d->params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					d->params[i].user = 0;
				}
			}
		}
		spa_node_emit_info(&d->hooks, &d->info);
	}
	d->info.change_mask = old;
}