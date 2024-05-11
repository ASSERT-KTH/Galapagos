static void set_timeout(struct impl *this, uint64_t next_time)
{
	spa_log_trace(this->log, "set timeout %"PRIu64, next_time);
	this->timerspec.it_value.tv_sec = next_time / SPA_NSEC_PER_SEC;
	this->timerspec.it_value.tv_nsec = next_time % SPA_NSEC_PER_SEC;
	spa_system_timerfd_settime(this->data_system,
			this->timer_source.fd, SPA_FD_TIMER_ABSTIME, &this->timerspec, NULL);
}