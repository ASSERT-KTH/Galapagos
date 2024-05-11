static void emit_node_info(struct impl *this, bool full)
{
	char node_group_buf[256];
	char *node_group = NULL;

	if (this->transport && (this->transport->profile & SPA_BT_PROFILE_BAP_SINK)) {
		spa_scnprintf(node_group_buf, sizeof(node_group_buf), "bluez-iso-%s-cig-%d",
				this->transport->device->adapter->address,
				this->transport->bap_cig);
		node_group = node_group_buf;
	} else if (this->transport && (this->transport->profile & SPA_BT_PROFILE_BAP_BROADCAST_SINK)) {
		spa_scnprintf(node_group_buf, sizeof(node_group_buf), "bluez-iso-%s-big-%d",
				this->transport->device->adapter->address,
				this->transport->bap_big);
		node_group = node_group_buf;
	}

	struct spa_dict_item node_info_items[] = {
		{ SPA_KEY_DEVICE_API, "bluez5" },
		{ SPA_KEY_MEDIA_CLASS, this->is_internal ? "Audio/Sink/Internal" :
		  this->is_output ? "Audio/Sink" : "Stream/Input/Audio" },
		{ "media.name", ((this->transport && this->transport->device->name) ?
					this->transport->device->name : this->codec->bap ? "BAP" : "A2DP" ) },
		{ SPA_KEY_NODE_DRIVER, this->is_output ? "true" : "false" },
		{ "node.group", node_group },
	};
	uint64_t old = full ? this->info.change_mask : 0;
	if (full)
		this->info.change_mask = this->info_all;
	if (this->info.change_mask) {
		this->info.props = &SPA_DICT_INIT_ARRAY(node_info_items);
		spa_node_emit_info(&this->hooks, &this->info);
		this->info.change_mask = old;
	}
}