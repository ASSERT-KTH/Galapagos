static void clear_buffers(struct impl *this)
{
	if (this->n_buffers > 0) {
		spa_log_debug(this->log, "%p: clearing buffers", this);
		spa_list_init(&this->queued_output_buffers);
		this->n_buffers = 0;
	}
}