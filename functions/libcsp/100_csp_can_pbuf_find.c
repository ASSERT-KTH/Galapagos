csp_can_pbuf_element_t *csp_can_pbuf_find(uint32_t id, uint32_t mask, CSP_BASE_TYPE *task_woken)
{
	for (int i = 0; i < PBUF_ELEMENTS; i++) {
		if ((csp_can_pbuf[i].state == BUF_USED) && ((csp_can_pbuf[i].cfpid & mask) == (id & mask))) {
			csp_can_pbuf[i].last_used = (task_woken) ? csp_get_ms_isr() : csp_get_ms();
			return &csp_can_pbuf[i];
		}
	}
	return NULL;
}