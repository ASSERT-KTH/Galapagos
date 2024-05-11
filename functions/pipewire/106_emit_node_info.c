static void emit_node_info(struct state *this, bool full)
{
	uint64_t old = full ? this->info.change_mask : 0;

	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		struct spa_dict_item items[4];
		uint32_t i, n_items = 0;

		items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_DEVICE_API, "avb");
		items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_MEDIA_CLASS, "Audio/Source");
		items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_DRIVER, "true");
		this->info.props = &SPA_DICT_INIT(items, n_items);

		if (this->info.change_mask & SPA_NODE_CHANGE_MASK_PARAMS) {
			for (i = 0; i < this->info.n_params; i++) {
				if (this->params[i].user > 0) {
					this->params[i].flags ^= SPA_PARAM_INFO_SERIAL;
					this->params[i].user = 0;
				}
			}
		}
		spa_node_emit_info(&this->hooks, &this->info);

		this->info.change_mask = old;
	}
}