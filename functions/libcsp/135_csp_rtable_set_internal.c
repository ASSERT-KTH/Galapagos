int csp_rtable_set_internal(uint8_t address, uint8_t netmask, csp_iface_t *ifc, uint8_t via) {

	/* Validates options */
	if ((netmask != 0) && (netmask != CSP_ID_HOST_SIZE)) {
		csp_log_error("%s: invalid netmask in route: address %u, netmask %u, interface %p, via %u", __FUNCTION__, address, netmask, ifc, via);
		return CSP_ERR_INVAL;
	}

	/* Set route */
        const unsigned int ri = (netmask == 0) ? CSP_DEFAULT_ROUTE : address;
        rtable[ri].iface = ifc;
        rtable[ri].via = via;

	return CSP_ERR_NONE;
}