void csp_rtable_free(void) {
	for (csp_rtable_t * i = rtable; (i);) {
		void * freeme = i;
		i = i->next;
		csp_free(freeme);
	}
	rtable = NULL;
}