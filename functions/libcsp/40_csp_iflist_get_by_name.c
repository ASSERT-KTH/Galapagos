csp_iface_t * csp_iflist_get_by_name(const char *name) {
	csp_iface_t *ifc = interfaces;
	while(ifc) {
		if (strncasecmp(ifc->name, name, CSP_IFLIST_NAME_MAX) == 0) {
			break;
		}
		ifc = ifc->next;
	}
	return ifc;
}