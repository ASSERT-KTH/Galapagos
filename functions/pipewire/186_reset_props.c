static void reset_props(struct props *props)
{
	props->freewheel = DEFAULT_FREEWHEEL;
	spa_zero(props->clock_name);
	props->clock_id = CLOCK_MONOTONIC;
	props->freewheel_wait = DEFAULT_FREEWHEEL_WAIT;
	props->resync_ms = DEFAULT_RESYNC_MS;
}