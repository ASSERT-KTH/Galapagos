int csp_thread_create(csp_thread_func_t routine, const char * const thread_name, unsigned int stack_size, void * parameters, unsigned int priority, csp_thread_handle_t * return_handle) {

	csp_thread_handle_t handle;
#if (tskKERNEL_VERSION_MAJOR >= 8)
	portBASE_TYPE ret = xTaskCreate(routine, thread_name, stack_size, parameters, priority, &handle);
#else
	portBASE_TYPE ret = xTaskCreate(routine, (signed char *) thread_name, stack_size, parameters, priority, &handle);
#endif
	if (ret != pdTRUE) {
		return CSP_ERR_NOMEM;
	}
	if (return_handle) {
		*return_handle = handle;
	}
	return CSP_ERR_NONE;
}