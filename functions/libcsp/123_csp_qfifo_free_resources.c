void csp_qfifo_free_resources(void) {

	for (int prio = 0; prio < CSP_ROUTE_FIFOS; prio++) {
		if (qfifo[prio]) {
			csp_queue_remove(qfifo[prio]);
			qfifo[prio] = NULL;
		}
	}

#if (CSP_USE_QOS)
	if (qfifo_events) {
		csp_queue_remove(qfifo_events);
		qfifo_events = NULL;
	}
#endif

}