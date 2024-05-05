int csp_zmqhub_tx(const csp_route_t * route, csp_packet_t * packet) {

	zmq_driver_t * drv = route->iface->driver_data;

	const uint8_t dest = (route->via != CSP_NO_VIA_ADDRESS) ? route->via : packet->id.dst;

	uint16_t length = packet->length;
	uint8_t * destptr = ((uint8_t *) &packet->id) - sizeof(dest);
	memcpy(destptr, &dest, sizeof(dest));
	csp_bin_sem_wait(&drv->tx_wait, 1000); /* Using ZMQ in thread safe manner*/
	int result = zmq_send(drv->publisher, destptr, length + sizeof(packet->id) + sizeof(dest), 0);
	csp_bin_sem_post(&drv->tx_wait); /* Release tx semaphore */
	if (result < 0) {
		csp_log_error("ZMQ send error: %u %s\r\n", result, zmq_strerror(zmq_errno()));
	}

	csp_buffer_free(packet);

	return CSP_ERR_NONE;

}