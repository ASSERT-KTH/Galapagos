const csp_route_t * csp_rtable_find_route(uint8_t dest_address)
{
    csp_rtable_t * entry = csp_rtable_find(dest_address, CSP_ID_HOST_SIZE, 0);
    if (entry) {
	return &entry->route;
    }
    return NULL;
}