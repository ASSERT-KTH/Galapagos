static int csp_conn_flush_rx_queue(csp_conn_t * conn) {

	csp_packet_t * packet;

	int prio;

	/* Flush packet queues */
	for (prio = 0; prio < CSP_RX_QUEUES; prio++) {
		while (csp_queue_dequeue(conn->rx_queue[prio], &packet, 0) == CSP_QUEUE_OK)
			if (packet != NULL)
				csp_buffer_free(packet);
	}

	/* Flush event queue */
#if (CSP_USE_QOS)
	int event;
	while (csp_queue_dequeue(conn->rx_event, &event, 0) == CSP_QUEUE_OK);
#endif

	return CSP_ERR_NONE;

}