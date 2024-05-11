static void set_timeout(struct state *state, uint64_t next_time)
{
	struct itimerspec ts;
	uint64_t time_utc;

	spa_log_trace(state->log, "set timeout %"PRIu64, next_time);

        time_utc = next_time > TAI_OFFSET ? TAI_TO_UTC(next_time) : 0;
	ts.it_value.tv_sec = time_utc / SPA_NSEC_PER_SEC;
	ts.it_value.tv_nsec = time_utc % SPA_NSEC_PER_SEC;
        ts.it_interval.tv_sec = 0;
        ts.it_interval.tv_nsec = 0;
	spa_system_timerfd_settime(state->data_system,
			state->timer_source.fd, SPA_FD_TIMER_ABSTIME, &ts, NULL);
}