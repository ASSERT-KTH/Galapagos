static int csp_sys_log_and_return(const char * function, int res) {

	if (res != 0) {
		csp_log_warn("%s: failed to execute, returned error: %d, errno: %d", function, res, errno);
		return CSP_ERR_INVAL; // no real suitable error code
	}
	csp_log_info("%s: executed", function);
	return CSP_ERR_NONE;

}