static int csp_route_check_options(csp_iface_t *iface, csp_packet_t *packet)
{
#if (CSP_USE_XTEA == 0)
	/* Drop XTEA packets */
	if (packet->id.flags & CSP_FXTEA) {
		csp_log_error("Received XTEA encrypted packet, but CSP was compiled without XTEA support. Discarding packet");
		iface->autherr++;
		return CSP_ERR_NOTSUP;
	}
#endif

#if (CSP_USE_HMAC == 0)
	/* Drop HMAC packets */
	if (packet->id.flags & CSP_FHMAC) {
		csp_log_error("Received packet with HMAC, but CSP was compiled without HMAC support. Discarding packet");
		iface->autherr++;
		return CSP_ERR_NOTSUP;
	}
#endif

#if (CSP_USE_RDP == 0)
	/* Drop RDP packets */
	if (packet->id.flags & CSP_FRDP) {
		csp_log_error("Received RDP packet, but CSP was compiled without RDP support. Discarding packet");
		iface->rx_error++;
		return CSP_ERR_NOTSUP;
	}
#endif
	return CSP_ERR_NONE;
}