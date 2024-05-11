static void reset_props(struct props *props)
{
	props->format = 0;
	props->channels = 0;
	props->rate = 0;
	strncpy(props->clock_name, DEFAULT_CLOCK_NAME, sizeof(props->clock_name));
	props->debug = false;
	props->driver = true;
}