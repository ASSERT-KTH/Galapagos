static int clear_buffers(struct impl *this, struct port *port)
{
	if (port->n_buffers > 0) {
		spa_log_debug(this->log, "%p: clear buffers", this);
		port->n_buffers = 0;
		spa_list_init(&port->empty);
		this->started = false;
	}
	return 0;
}