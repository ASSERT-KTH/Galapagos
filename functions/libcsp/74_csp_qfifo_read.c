int csp_qfifo_read(csp_qfifo_t * input) {

#if (CSP_USE_QOS)
	int prio, found, event;

	/* Wait for packet in any queue */
	if (csp_queue_dequeue(qfifo_events, &event, FIFO_TIMEOUT) != CSP_QUEUE_OK)
		return CSP_ERR_TIMEDOUT;

	/* Find packet with highest priority */
	found = 0;
	for (prio = 0; prio < CSP_ROUTE_FIFOS; prio++) {
		if (csp_queue_dequeue(qfifo[prio], input, 0) == CSP_QUEUE_OK) {
			found = 1;
			break;
		}
	}

	if (!found) {
		csp_log_warn("Spurious wakeup: No packet found");
		return CSP_ERR_TIMEDOUT;
	}
#else
	if (csp_queue_dequeue(qfifo[0], input, FIFO_TIMEOUT) != CSP_QUEUE_OK)
		return CSP_ERR_TIMEDOUT;
#endif

	return CSP_ERR_NONE;

}