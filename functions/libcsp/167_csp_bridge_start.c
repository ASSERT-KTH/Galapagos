int csp_bridge_start(unsigned int task_stack_size, unsigned int task_priority, csp_iface_t * if_a, csp_iface_t * if_b) {

	/* Set static references to A/B side of bridge */
	bif_a.iface = if_a;
	bif_b.iface = if_b;

	static csp_thread_handle_t handle;
	int ret = csp_thread_create(csp_bridge, "BRIDGE", task_stack_size, NULL, task_priority, &handle);

	if (ret != 0) {
		csp_log_error("Failed to start task");
		return CSP_ERR_NOMEM;
	}

	return CSP_ERR_NONE;

}