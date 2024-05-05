static inline sfp_header_t * csp_sfp_header_remove(csp_packet_t * packet) {

	if ((packet->id.flags & CSP_FFRAG) == 0) {
		return NULL;
	}
	sfp_header_t * header;
	if (packet->length < sizeof(*header)) {
		return NULL;
	}
        header = (sfp_header_t *) &packet->data[packet->length - sizeof(*header)];
	packet->length -= sizeof(*header);

	header->offset = csp_ntoh32(header->offset);
	header->totalsize = csp_ntoh32(header->totalsize);

	if (header->offset > header->totalsize) {
		return NULL;
	}

	return header;
}