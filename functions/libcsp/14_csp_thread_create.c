int csp_thread_create(csp_thread_func_t routine, const char * const thread_name, unsigned int stack_size, void * parameters, unsigned int priority, csp_thread_handle_t * return_handle) {

	pthread_attr_t attributes;
	if (pthread_attr_init(&attributes) != 0) {
		return CSP_ERR_NOMEM;
	}
	// if stack size is 0, use default stack size
	if (stack_size) {
		unsigned int min_stack_size = PTHREAD_STACK_MIN;// use at least one memory
		while (min_stack_size < stack_size) { // must reach at least the provided size
			min_stack_size += PTHREAD_STACK_MIN;// keep memory page boundary (some systems may fail otherwise))
		}
		pthread_attr_setstacksize(&attributes, min_stack_size);
	}
	pthread_attr_setdetachstate(&attributes, PTHREAD_CREATE_DETACHED);// no need to join with thread to free its resources

	pthread_t handle;
	int return_code = pthread_create(&handle, &attributes, routine, parameters);
	pthread_attr_destroy(&attributes);

	if (return_code != 0) {
		return CSP_ERR_NOMEM;
	}
	if (return_handle) {
		*return_handle = handle;
	}

	return CSP_ERR_NONE;
}