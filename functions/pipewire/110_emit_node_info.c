static void emit_node_info(struct impl *this, bool full)
{
	const struct spa_dict_item hu_node_info_items[] = {
		{ SPA_KEY_DEVICE_API, "bluez5" },
		{ SPA_KEY_MEDIA_CLASS, this->is_internal ? "Audio/Sink/Internal" : "Audio/Sink" },
		{ SPA_KEY_NODE_DRIVER, "true" },
	};

	const struct spa_dict_item ag_node_info_items[] = {
		{ SPA_KEY_DEVICE_API, "bluez5" },
		{ SPA_KEY_MEDIA_CLASS, "Stream/Input/Audio" },
		{ "media.name", ((this->transport && this->transport->device->name) ?
				 this->transport->device->name : "HSP/HFP") },
		{ SPA_KEY_MEDIA_ROLE, "Communication" },
	};
	bool is_ag = this->transport &&
		(this->transport->profile & SPA_BT_PROFILE_HEADSET_AUDIO_GATEWAY);
	uint64_t old = full ? this->info.change_mask : 0;

	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		this->info.props = is_ag ?
			&SPA_DICT_INIT_ARRAY(ag_node_info_items) :
			&SPA_DICT_INIT_ARRAY(hu_node_info_items);
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}