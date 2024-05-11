int pw_main_loop_run(struct pw_main_loop *loop)
{
	int res = 0;

	pw_log_debug("%p: run", loop);

	loop->running = true;
	pw_loop_enter(loop->loop);
	while (loop->running) {
		if ((res = pw_loop_iterate(loop->loop, -1)) < 0) {
			if (res == -EINTR)
				continue;
			pw_log_warn("%p: iterate error %d (%s)",
					loop, res, spa_strerror(res));
		}
	}
	pw_loop_leave(loop->loop);
	return res;
}