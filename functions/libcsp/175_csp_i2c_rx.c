void csp_i2c_rx(csp_iface_t * iface, csp_i2c_frame_t * frame, void * pxTaskWoken) {

	/* Validate input */
	if (frame == NULL) {
		return;
	}

	if (frame->len < sizeof(csp_id_t)) {
		iface->frame++;
		(pxTaskWoken != NULL) ? csp_buffer_free_isr(frame) : csp_buffer_free(frame);
		return;
	}

	/* Strip the CSP header off the length field before converting to CSP packet */
	frame->len -= sizeof(csp_id_t);

	if (frame->len > csp_buffer_data_size()) { // consistency check, should never happen
		iface->rx_error++;
		(pxTaskWoken != NULL) ? csp_buffer_free_isr(frame) : csp_buffer_free(frame);
		return;
	}

	/* Convert the packet from network to host order */
	csp_packet_t * packet = (csp_packet_t *) frame;
	packet->id.ext = csp_ntoh32(packet->id.ext);

	/* Receive the packet in CSP */
	csp_qfifo_write(packet, iface, pxTaskWoken);

}