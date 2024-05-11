EXPORT_SYMBOL int INTERNAL(snd_ctl_elem_info_get_dimensions)(const snd_ctl_elem_info_t *obj ATTRIBUTE_UNUSED)
#else
int snd_ctl_elem_info_get_dimensions(const snd_ctl_elem_info_t *obj)
#endif
{
#if 0 /* deprecated */
	int i;

	assert(obj);
	for (i = 3; i >= 0; i--)
		if (obj->dimen.d[i])
			break;
	return i + 1;
#else
	return -EINVAL;
#endif
}