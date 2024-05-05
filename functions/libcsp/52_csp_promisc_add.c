void csp_promisc_add(csp_packet_t * packet) {

	if (csp_promisc_enabled == 0)
		return;

	if (csp_promisc_queue != NULL) {
		/* Make a copy of the message and queue it to the promiscuous task */
		csp_packet_t *packet_copy = csp_buffer_clone(packet);
		if (packet_copy != NULL) {
			if (csp_queue_enqueue(csp_promisc_queue, &packet_copy, 0) != CSP_QUEUE_OK) {
				csp_log_error("Promiscuous mode input queue full");
				csp_buffer_free(packet_copy);
			}
		}
	}

}