int csp_conn_get_rxq(int prio) {

#if (CSP_USE_QOS)
	return prio;
#else
	return 0;
#endif

}