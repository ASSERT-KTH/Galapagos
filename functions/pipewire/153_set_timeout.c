static void set_timeout(struct impl *impl, uint64_t time)
{
	struct itimerspec ts;
	ts.it_value.tv_sec = time / SPA_NSEC_PER_SEC;
	ts.it_value.tv_nsec = time % SPA_NSEC_PER_SEC;
	ts.it_interval.tv_sec = 0;
	ts.it_interval.tv_nsec = 0;
	pw_loop_update_timer(impl->loop, impl->timer, &ts.it_value, &ts.it_interval, true);
	impl->next_time = time;
}