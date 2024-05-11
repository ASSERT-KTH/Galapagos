int snd_hctl_elem_read(snd_hctl_elem_t *elem, snd_ctl_elem_value_t * value)
{
	assert(elem);
	assert(elem->hctl);
	assert(value);
	value->id = elem->id;
	return snd_ctl_elem_read(elem->hctl->ctl, value);
}