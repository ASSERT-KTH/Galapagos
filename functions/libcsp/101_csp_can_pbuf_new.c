csp_can_pbuf_element_t *csp_can_pbuf_new(uint32_t id, CSP_BASE_TYPE *task_woken)
{
	uint32_t now = (task_woken) ? csp_get_ms_isr() : csp_get_ms();

	for (int i = 0; i < PBUF_ELEMENTS; i++) {

		/* Perform cleanup in used pbufs */
		if (csp_can_pbuf[i].state == BUF_USED) {
			if (now - csp_can_pbuf[i].last_used > PBUF_TIMEOUT_MS)
				csp_can_pbuf_free(&csp_can_pbuf[i], task_woken);
		}

		if (csp_can_pbuf[i].state == BUF_FREE) {
			csp_can_pbuf[i].state = BUF_USED;
			csp_can_pbuf[i].cfpid = id;
			csp_can_pbuf[i].remain = 0;
			csp_can_pbuf[i].last_used = now;
			return &csp_can_pbuf[i];
		}

	}

	return NULL;

}