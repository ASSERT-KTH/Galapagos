static void emit_node_info(struct impl *this, bool full)
{
	uint32_t i;
	uint64_t old = full ? this->info.change_mask : 0;

	spa_log_debug(this->log, "%p: info full:%d change:%08"PRIx64,
			this, full, this->info.change_mask);

	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		if (this->info.change_mask & SPA_NODE_CHANGE_MASK_PARAMS) {
			for (i = 0; i < this->info.n_params; i++) {
				if (this->params[i].user > 0) {
					this->params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					this->params[i].user = 0;
					spa_log_debug(this->log, "param %d flags:%08x",
							i, this->params[i].flags);
				}
			}
		}
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}