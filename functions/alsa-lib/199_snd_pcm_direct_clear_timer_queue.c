int snd_pcm_direct_clear_timer_queue(snd_pcm_direct_t *dmix)
{
	int changed = 0;
	if (dmix->timer_need_poll) {
		while (poll(&dmix->timer_fd, 1, 0) > 0) {
			changed++;
			/* we don't need the value */
			if (dmix->tread) {
				snd_timer_tread_t rbuf[4];
				snd_timer_read(dmix->timer, rbuf, sizeof(rbuf));
			} else {
				snd_timer_read_t rbuf;
				snd_timer_read(dmix->timer, &rbuf, sizeof(rbuf));
			}
		}
	} else {
		if (dmix->tread) {
			snd_timer_tread_t rbuf[4];
			int len;
			while ((len = snd_timer_read(dmix->timer, rbuf,
						     sizeof(rbuf))) > 0
						     && (++changed) &&
			       len != sizeof(rbuf[0]))
				;
		} else {
			snd_timer_read_t rbuf;
			while (snd_timer_read(dmix->timer, &rbuf, sizeof(rbuf)) > 0)
				changed++;
		}
	}
	return changed;
}