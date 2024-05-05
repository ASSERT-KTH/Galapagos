csp_conn_t * csp_conn_find(uint32_t id, uint32_t mask) {

	/* Search for matching connection */
	id = (id & mask);
	for (int i = 0; i < csp_conf.conn_max; i++) {
		csp_conn_t * conn = &arr_conn[i];
		if ((conn->state == CONN_OPEN) && (conn->type == CONN_CLIENT) && ((conn->idin.ext & mask) == id)) {
			return conn;
		}
	}
	
	return NULL;

}