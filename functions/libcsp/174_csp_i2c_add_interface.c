int csp_i2c_add_interface(csp_iface_t * iface) {

	if ((iface == NULL) || (iface->name == NULL) || (iface->interface_data == NULL)) {
		return CSP_ERR_INVAL;
	}

	csp_i2c_interface_data_t * ifdata = iface->interface_data;
	if (ifdata->tx_func == NULL) {
		return CSP_ERR_INVAL;
	}

        const unsigned int max_data_size = csp_buffer_data_size();
        if ((iface->mtu == 0) || (iface->mtu > max_data_size)) {
		iface->mtu = max_data_size;
	}

        iface->nexthop = csp_i2c_tx;

	return csp_iflist_add(iface);
}