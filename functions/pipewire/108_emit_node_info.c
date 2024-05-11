static void emit_node_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->info.change_mask : 0;
	char latency[64];
	char media_name[256];

	spa_scnprintf(
		media_name,
		sizeof(media_name),
		"%s (codec %s)",
		((this->transport && this->transport->device->name) ?
			this->transport->device->name : this->codec->bap ? "BAP" : "A2DP"),
		this->codec->description
	);

	struct spa_dict_item node_info_items[] = {
		{ SPA_KEY_DEVICE_API, "bluez5" },
		{ SPA_KEY_MEDIA_CLASS, this->is_internal ? "Audio/Source/Internal" :
		  this->is_input ? "Audio/Source" : "Stream/Output/Audio" },
		{ SPA_KEY_NODE_LATENCY, this->is_input ? "" : latency },
		{ "media.name", media_name },
		{ SPA_KEY_NODE_DRIVER, this->is_input ? "true" : "false" },
	};

	spa_scnprintf(latency, sizeof(latency), "%d/48000", this->node_latency);

	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		this->info.props = &SPA_DICT_INIT_ARRAY(node_info_items);
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}