static CSP_DEFINE_TASK(csp_task_router) {

	/* Here there be routing */
	while (1) {
		csp_route_work(FIFO_TIMEOUT);
	}

	return CSP_TASK_RETURN;

}