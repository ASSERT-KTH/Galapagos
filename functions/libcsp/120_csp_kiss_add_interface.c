int csp_kiss_add_interface(csp_iface_t * iface) {

	if ((iface == NULL) || (iface->name == NULL) || (iface->interface_data == NULL)) {
		return CSP_ERR_INVAL;
	}

        csp_kiss_interface_data_t * ifdata = iface->interface_data;
	if (ifdata->tx_func == NULL) {
		return CSP_ERR_INVAL;
	}

	if (csp_mutex_create(&ifdata->lock) != CSP_MUTEX_OK) {
		return CSP_ERR_NOMEM;
        }

	ifdata->max_rx_length = CSP_HEADER_LENGTH + csp_buffer_data_size(); // CSP header + CSP data
	ifdata->rx_length = 0;
	ifdata->rx_mode = KISS_MODE_NOT_STARTED;
	ifdata->rx_first = false;
	ifdata->rx_packet = NULL;

        const unsigned int max_data_size = csp_buffer_data_size() - sizeof(uint32_t); // compensate for the added CRC32
        if ((iface->mtu == 0) || (iface->mtu > max_data_size)) {
            iface->mtu = max_data_size;
        }

	iface->nexthop = csp_kiss_tx;

	return csp_iflist_add(iface);
}