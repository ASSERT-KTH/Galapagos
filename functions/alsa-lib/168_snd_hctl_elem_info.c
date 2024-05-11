int snd_hctl_elem_info(snd_hctl_elem_t *elem, snd_ctl_elem_info_t *info)
{
	assert(elem);
	assert(elem->hctl);
	assert(info);
	info->id = elem->id;
	return snd_ctl_elem_info(elem->hctl->ctl, info);
}