static void emit_node_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->info.change_mask : 0;
	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		struct spa_dict_item items[3];

		items[0] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_DRIVER, "true");
		items[1] = SPA_DICT_ITEM_INIT("clock.id", clock_id_to_name(this->props.clock_id));
		items[2] = SPA_DICT_ITEM_INIT("clock.name", this->props.clock_name);

		this->info.props = &SPA_DICT_INIT(items, 3);
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}