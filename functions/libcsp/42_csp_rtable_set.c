int csp_rtable_set(uint8_t address, uint8_t netmask, csp_iface_t *ifc, uint8_t via) {

	/* Legacy reference to default route (the old way) */
	if (address == CSP_DEFAULT_ROUTE) {
		netmask = 0;
		address = 0;
	}

	/* Validates options */
	if (((address > CSP_ID_HOST_MAX) && (address != 255)) || (ifc == NULL) || (netmask > CSP_ID_HOST_SIZE)) {
		csp_log_error("%s: invalid route: address %u, netmask %u, interface %p (%s), via %u",
                              __FUNCTION__, address, netmask, ifc, (ifc != NULL) ? ifc->name : "", via);
		return CSP_ERR_INVAL;
	}

        return csp_rtable_set_internal(address, netmask, ifc, via);
}