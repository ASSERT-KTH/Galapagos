int csp_route_start_task(unsigned int task_stack_size, unsigned int task_priority) {

	int ret = csp_thread_create(csp_task_router, "RTE", task_stack_size, NULL, task_priority, NULL);
	if (ret != 0) {
		csp_log_error("Failed to start router task, error: %d", ret);
		return ret;
	}

	return CSP_ERR_NONE;

}