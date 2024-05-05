int csp_conn_enqueue_packet(csp_conn_t * conn, csp_packet_t * packet) {

	if (!conn)
		return CSP_ERR_INVAL;

	int rxq;
	if (packet != NULL) {
		rxq = csp_conn_get_rxq(packet->id.pri);
	} else {
		rxq = CSP_RX_QUEUES - 1;
	}

	if (csp_queue_enqueue(conn->rx_queue[rxq], &packet, 0) != CSP_QUEUE_OK) {
		csp_log_error("RX queue %p full with %u items", conn->rx_queue[rxq], csp_queue_size(conn->rx_queue[rxq]));
		return CSP_ERR_NOMEM;
	}

#if (CSP_USE_QOS)
	int event = 0;
	if (csp_queue_enqueue(conn->rx_event, &event, 0) != CSP_QUEUE_OK) {
		csp_log_error("QOS event queue full");
		return CSP_ERR_NOMEM;
	}
#endif

	return CSP_ERR_NONE;
}