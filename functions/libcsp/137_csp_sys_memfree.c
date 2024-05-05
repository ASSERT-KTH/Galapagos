uint32_t csp_sys_memfree(void) {

	uint32_t total = 0;
	struct sysinfo info;
	sysinfo(&info);
	total = info.freeram * info.mem_unit;
	return total;

}