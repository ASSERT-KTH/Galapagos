int csp_promisc_enable(unsigned int queue_size) {

	/* If queue already initialised */
	if (csp_promisc_queue != NULL) {
		csp_promisc_enabled = 1;
		return CSP_ERR_NONE;
	}

	/* Create packet queue */
	csp_promisc_queue = csp_queue_create(queue_size, sizeof(csp_packet_t *));

	if (csp_promisc_queue == NULL)
		return CSP_ERR_INVAL;

	csp_promisc_enabled = 1;
	return CSP_ERR_NONE;

}