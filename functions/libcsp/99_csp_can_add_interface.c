int csp_can_add_interface(csp_iface_t * iface) {

	if ((iface == NULL) || (iface->name == NULL) || (iface->interface_data == NULL)) {
		return CSP_ERR_INVAL;
	}

        csp_can_interface_data_t * ifdata = iface->interface_data;
	if (ifdata->tx_func == NULL) {
		return CSP_ERR_INVAL;
	}

        if ((iface->mtu == 0) || (iface->mtu > MAX_CAN_DATA_SIZE)) {
            iface->mtu = MAX_CAN_DATA_SIZE;
        }

        ifdata->cfp_frame_id = 0;

	iface->nexthop = csp_can_tx;

	return csp_iflist_add(iface);
}