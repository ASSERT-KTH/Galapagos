int csp_crc32_append(csp_packet_t * packet, bool include_header) {

	uint32_t crc;

	if ((packet->length + sizeof(crc)) > csp_buffer_data_size()) {
		return CSP_ERR_NOMEM;
	}

	/* Calculate CRC32, convert to network byte order */
	if (include_header) {
		crc = csp_crc32_memory((uint8_t *) &packet->id, packet->length + sizeof(packet->id));
	} else {
		crc = csp_crc32_memory(packet->data, packet->length);
	}
	/* Convert to network byte order */
	crc = csp_hton32(crc);

	/* Copy checksum to packet */
	memcpy(&packet->data[packet->length], &crc, sizeof(crc));
	packet->length += sizeof(crc);

	return CSP_ERR_NONE;

}