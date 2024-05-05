int csp_zmqhub_init_w_endpoints(uint8_t addr,
                                const char * publisher_endpoint,
				const char * subscriber_endpoint,
                                uint32_t flags,
                                csp_iface_t ** return_interface) {

	uint8_t * rxfilter = NULL;
	unsigned int rxfilter_count = 0;

	if (addr != CSP_NO_VIA_ADDRESS) { // != 255
		rxfilter = &addr;
		rxfilter_count = 1;
	}

	return csp_zmqhub_init_w_name_endpoints_rxfilter(NULL,
							 rxfilter, rxfilter_count,
							 publisher_endpoint,
							 subscriber_endpoint,
							 flags,
                                                         return_interface);
}