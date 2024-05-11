static int clear_buffers(struct state *this)
{
	if (this->n_buffers > 0) {
		spa_list_init(&this->ready);
		this->n_buffers = 0;
	}
	return 0;
}