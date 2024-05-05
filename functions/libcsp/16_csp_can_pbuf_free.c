int csp_can_pbuf_free(csp_can_pbuf_element_t *buf, CSP_BASE_TYPE *task_woken)
{
	/* Free CSP packet */
	if (buf->packet != NULL) {
		if (task_woken == NULL) {
			csp_buffer_free(buf->packet);
		} else {
			csp_buffer_free_isr(buf->packet);
		}
	}

	/* Mark buffer element free */
	buf->packet = NULL;
	buf->rx_count = 0;
	buf->cfpid = 0;
	buf->last_used = 0;
	buf->remain = 0;
	buf->state = BUF_FREE;

	return CSP_ERR_NONE;
}