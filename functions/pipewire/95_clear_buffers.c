static int clear_buffers(struct node *this, struct port *port)
{
	uint32_t i, j;
	struct impl *impl = this->impl;

	for (i = 0; i < port->n_buffers; i++) {
		struct buffer *b = &port->buffers[i];
		struct mem *m;

		spa_log_debug(this->log, "node %p: clear buffer %d", this, i);

		for (j = 0; j < b->buffer.n_datas; j++) {
			struct spa_data *d = &b->datas[j];

			if (d->type == SPA_DATA_DmaBuf ||
			    d->type == SPA_DATA_MemFd) {
				uint32_t id;

				id = SPA_PTR_TO_UINT32(b->buffer.datas[j].data);
				m = pw_array_get_unchecked(&impl->mems, id, struct mem);
				m->ref--;
			}
		}
		m = pw_array_get_unchecked(&impl->mems, b->memid, struct mem);
		m->ref--;
	}
	port->n_buffers = 0;
	return 0;
}