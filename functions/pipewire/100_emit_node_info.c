static void emit_node_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->node_info.change_mask : 0;

	if (full)
		this->node_info.change_mask = this->node_info_all;
	if (this->node_info.change_mask) {
		this->node_info.props = &SPA_DICT_INIT_ARRAY(node_info_items);
		spa_node_emit_info(&this->hooks, &this->node_info);
		this->node_info.change_mask = old;
	}
}