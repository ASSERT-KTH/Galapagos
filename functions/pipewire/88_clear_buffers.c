static int clear_buffers(struct impl *this, struct port *port)
{
	if (port->n_buffers > 0) {
		spa_log_debug(this->log, "%p: clear buffers", this);
		lock_renderer(this);
		spa_vulkan_blit_use_buffers(&this->state, &this->state.streams[port->stream_id], 0, &port->current_format, 0, NULL);
		spa_vulkan_blit_clear_pass(&this->state, &this->pass);
		unlock_renderer(this);
		port->n_buffers = 0;
		spa_list_init(&port->empty);
		spa_list_init(&port->ready);
	}
	return 0;
}