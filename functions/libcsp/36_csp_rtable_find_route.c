const csp_route_t * csp_rtable_find_route(uint8_t dest_address) {

	if (rtable[dest_address].iface != NULL) {
		return &rtable[dest_address];
	}
	if (rtable[CSP_DEFAULT_ROUTE].iface != NULL) {
		return &rtable[CSP_DEFAULT_ROUTE];
	}
	return NULL;

}