int csp_qfifo_init(void) {

	/* Create router fifos for each priority */
	for (int prio = 0; prio < CSP_ROUTE_FIFOS; prio++) {
		if (qfifo[prio] == NULL) {
			qfifo[prio] = csp_queue_create(csp_conf.fifo_length, sizeof(csp_qfifo_t));
			if (!qfifo[prio])
				return CSP_ERR_NOMEM;
		}
	}

#if (CSP_USE_QOS)
	/* Create QoS fifo notification queue */
	qfifo_events = csp_queue_create(csp_conf.fifo_length, sizeof(int));
	if (!qfifo_events) {
		return CSP_ERR_NOMEM;
	}
#endif

	return CSP_ERR_NONE;

}