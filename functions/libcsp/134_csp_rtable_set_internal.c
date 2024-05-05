int csp_rtable_set_internal(uint8_t address, uint8_t netmask, csp_iface_t *ifc, uint8_t via) {

	/* First see if the entry exists */
	csp_rtable_t * entry = csp_rtable_find(address, netmask, 1);

	/* If not, create a new one */
	if (!entry) {
		entry = csp_malloc(sizeof(*entry));
		if (entry == NULL) {
			return CSP_ERR_NOMEM;
		}

		entry->next = NULL;
		/* Add entry to linked-list */
		if (rtable == NULL) {
			/* This is the first interface to be added */
			rtable = entry;
		} else {
			/* One or more interfaces were already added */
			csp_rtable_t * i = rtable;
			while (i->next) {
				i = i->next;
			}
			i->next = entry;
		}
	}

	/* Fill in the data */
	entry->address = address;
	entry->netmask = netmask;
	entry->route.iface = ifc;
	entry->route.via = via;

	return CSP_ERR_NONE;
}