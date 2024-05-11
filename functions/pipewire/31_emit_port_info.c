static void emit_port_info(struct impl *this, bool full)
{
	uint64_t old = full ? this->port_info.change_mask : 0;

	if (full)
		this->port_info.change_mask = this->port_info_all;
	if (this->port_info.change_mask) {
		spa_node_emit_port_info(&this->hooks,
		                        SPA_DIRECTION_INPUT, 0, &this->port_info);
		this->port_info.change_mask = old;
	}
}