static void reset_props(struct props *props)
{
	memset(props->device, 0, sizeof(props->device));
	props->card_nr = 0;
	props->device_nr = 0;
	props->device_name_set = false;
}