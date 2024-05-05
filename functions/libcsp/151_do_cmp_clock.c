static int do_cmp_clock(struct csp_cmp_message *cmp) {

	csp_timestamp_t clock;
	clock.tv_sec = csp_ntoh32(cmp->clock.tv_sec);
	clock.tv_nsec = csp_ntoh32(cmp->clock.tv_nsec);

	int res = CSP_ERR_NONE;
	if (clock.tv_sec != 0) {
		// set time
		res = csp_clock_set_time(&clock);
		if (res != CSP_ERR_NONE) {
			csp_log_warn("csp_clock_set_time(sec=%"PRIu32", nsec=%"PRIu32") failed, error: %d", clock.tv_sec, clock.tv_nsec, res);
		}
	}

	csp_clock_get_time(&clock);

	cmp->clock.tv_sec = csp_hton32(clock.tv_sec);
	cmp->clock.tv_nsec = csp_hton32(clock.tv_nsec);

	return res;

}