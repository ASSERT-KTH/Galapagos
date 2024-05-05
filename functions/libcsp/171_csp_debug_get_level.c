int csp_debug_get_level(csp_debug_level_t level) {

	if (level <= CSP_LOCK) {
		return csp_debug_level_enabled[level];
	}
	return 0;
}