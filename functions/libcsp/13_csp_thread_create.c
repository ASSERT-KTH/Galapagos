int csp_thread_create(csp_thread_func_t routine, const char * const thread_name, unsigned int stack_size, void * parameters, unsigned int priority, csp_thread_handle_t * return_handle) {

	pthread_t handle;
	int res = pthread_create(&handle, NULL, routine, parameters);
	if (res) {
		return CSP_ERR_NOMEM;
	}
	if (return_handle) {
		*return_handle = handle;
	}

	return CSP_ERR_NONE;
}