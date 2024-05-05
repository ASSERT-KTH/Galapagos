int csp_crc32_verify(csp_packet_t * packet, bool include_header) {

	uint32_t crc;

	if (packet->length < sizeof(crc)) {
		return CSP_ERR_CRC32;
	}

	/* Calculate CRC32, convert to network byte order */
	if (include_header) {
		crc = csp_crc32_memory((uint8_t *) &packet->id, packet->length + sizeof(packet->id) - sizeof(crc));
	} else {
		crc = csp_crc32_memory(packet->data, packet->length - sizeof(crc));
	}
	crc = csp_hton32(crc);

	/* Compare calculated checksum with packet header */
	if (memcmp(&packet->data[packet->length] - sizeof(crc), &crc, sizeof(crc)) != 0) {
		/* CRC32 failed */
		return CSP_ERR_CRC32;
	}

	/* Strip CRC32 */
	packet->length -= sizeof(crc);
	return CSP_ERR_NONE;

}