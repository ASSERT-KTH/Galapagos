void csp_rtable_iterate(csp_rtable_iterator_t iter, void * ctx) {

	for (unsigned int i = 0; i < CSP_DEFAULT_ROUTE; ++i) {
		if (rtable[i].iface != NULL) {
			if (iter(ctx, i, CSP_ID_HOST_SIZE, &rtable[i]) == false) {
				return; // stopped by user
			}
		}
	}
	if (rtable[CSP_DEFAULT_ROUTE].iface) {
		iter(ctx, 0, 0, &rtable[CSP_DEFAULT_ROUTE]);
	}
}