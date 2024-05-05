void * csp_calloc(size_t nmemb, size_t size) {
	size = (nmemb * size); 
	void * ptr = csp_malloc(size);
	if (ptr) {
		memset(ptr, 0, size);
	}
	return ptr;
}