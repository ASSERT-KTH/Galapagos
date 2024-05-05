static rdp_header_t * csp_rdp_header_add(csp_packet_t * packet) {
	rdp_header_t * header;
	if ((packet->length + sizeof(*header)) > csp_buffer_data_size()) {
		return NULL;
	}
	header = (rdp_header_t *) &packet->data[packet->length];
	packet->length += sizeof(*header);
	memset(header, 0, sizeof(*header));
	return header;
}