void *csp_buffer_clone(void *buffer) {

	csp_packet_t *packet = (csp_packet_t *) buffer;
	if (!packet) {
		return NULL;
	}

	csp_packet_t *clone = csp_buffer_get(packet->length);
	if (clone) {
		memcpy(clone, packet, csp_buffer_size());
	}

	return clone;

}