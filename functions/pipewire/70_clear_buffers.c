static int clear_buffers(struct seq_state *this, struct seq_port *port)
{
	if (port->n_buffers > 0) {
		spa_list_init(&port->free);
		spa_list_init(&port->ready);
		port->n_buffers = 0;
	}
	return 0;
}