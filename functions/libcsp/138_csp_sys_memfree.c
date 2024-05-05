uint32_t csp_sys_memfree(void) {

	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	DWORDLONG freePhysicalMem = statex.ullAvailPhys;
	size_t total = (size_t) freePhysicalMem;
	return (uint32_t)total;

}