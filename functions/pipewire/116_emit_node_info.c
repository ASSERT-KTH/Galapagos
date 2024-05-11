static void emit_node_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->info.change_mask : 0;
	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		struct spa_dict_item items[8];
		char latency[64];
		snprintf(latency, sizeof(latency), "%d/%d",
				this->client->buffer_size, this->client->frame_rate);
		items[0] = SPA_DICT_ITEM_INIT(SPA_KEY_MEDIA_CLASS, "Audio/Source");
		items[1] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_NAME, "JACK Source");
		items[2] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_DRIVER, "true");
		items[3] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_PAUSE_ON_IDLE, "false");
		items[4] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_ALWAYS_PROCESS, "true");
		items[5] = SPA_DICT_ITEM_INIT("priority.driver", "30000");
		items[6] = SPA_DICT_ITEM_INIT("node.group", "jack-group");
		items[7] = SPA_DICT_ITEM_INIT(SPA_KEY_NODE_LATENCY, latency);
		this->info.props = &SPA_DICT_INIT_ARRAY(items);
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}