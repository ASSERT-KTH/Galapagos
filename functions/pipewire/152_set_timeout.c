static int set_timeout(struct impl *impl, uint64_t time)
{
	struct timespec timeout, interval;
	timeout.tv_sec = time / SPA_NSEC_PER_SEC;
	timeout.tv_nsec = time % SPA_NSEC_PER_SEC;
	interval.tv_sec = 0;
	interval.tv_nsec = 0;
	pw_loop_update_timer(impl->data_loop,
                                impl->timer, &timeout, &interval, true);
	return 0;
}