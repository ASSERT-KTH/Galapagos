static int do_cmp_route_set(struct csp_cmp_message *cmp) {

	csp_iface_t *ifc = csp_iflist_get_by_name(cmp->route_set.interface);
	if (ifc == NULL) {
		return CSP_ERR_INVAL;
	}

	if (csp_route_set(cmp->route_set.dest_node, ifc, cmp->route_set.next_hop_via) != CSP_ERR_NONE) {
		return CSP_ERR_INVAL;
	}

	return CSP_ERR_NONE;

}