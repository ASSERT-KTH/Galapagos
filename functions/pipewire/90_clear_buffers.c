static int clear_buffers(struct impl *this, struct port *port)
{
	if (port->n_buffers > 0) {
		spa_log_debug(this->log, "%p: clear buffers", this);
		spa_vulkan_compute_stop(&this->state);
		spa_vulkan_compute_use_buffers(&this->state, &this->state.streams[port->stream_id], 0, &port->current_format.info.dsp, 0, NULL);
		port->n_buffers = 0;
		spa_list_init(&port->empty);
		spa_list_init(&port->ready);
		this->started = false;
	}
	return 0;
}