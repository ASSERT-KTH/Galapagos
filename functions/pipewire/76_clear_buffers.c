static int clear_buffers(struct state *this, struct port *port)
{
	if (port->n_buffers > 0) {
		spa_list_init(&port->ready);
		port->n_buffers = 0;
	}
	return 0;
}