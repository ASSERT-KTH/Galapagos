int csp_sys_reboot(void) {

	if (csp_sys_reboot_callback) {
		return (csp_sys_reboot_callback)();
	}
	csp_log_warn("%s not supported - no user function set", __FUNCTION__);
	return CSP_ERR_NOTSUP;

}