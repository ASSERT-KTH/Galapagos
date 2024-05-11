static void emit_node_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->info.change_mask : 0;

	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		if (this->info.change_mask & SPA_NODE_CHANGE_MASK_PARAMS) {
			SPA_FOR_EACH_ELEMENT_VAR(this->params, p) {
				if (p->user > 0) {
					p->flags ^= SPA_PARAM_INFO_SERIAL;
					p->user = 0;
				}
			}
		}
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}