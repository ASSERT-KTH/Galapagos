static int csp_lo_tx(const csp_route_t * ifroute, csp_packet_t * packet) {

	/* Drop packet silently if not destined for us. This allows
	 * blackhole routing addresses by setting their nexthop to
	 * the loopback interface.
	 */
	if (packet->id.dst != csp_conf.address) {
		/* Consume and drop packet */
		csp_buffer_free(packet);
		return CSP_ERR_NONE;
	}

	/* Send back into CSP, notice calling from task so last argument must be NULL! */
	csp_qfifo_write(packet, &csp_if_lo, NULL);

	return CSP_ERR_NONE;

}