EXPORT_SYMBOL int INTERNAL(snd_ctl_elem_info_get_dimension)(const snd_ctl_elem_info_t *obj ATTRIBUTE_UNUSED, unsigned int idx ATTRIBUTE_UNUSED)
#else
int snd_ctl_elem_info_get_dimension(const snd_ctl_elem_info_t *obj, unsigned int idx)
#endif
{
#if 0 /* deprecated */
	assert(obj);
	if (idx > 3)
		return 0;
	return obj->dimen.d[idx];
#else /* deprecated */
	return -EINVAL;
#endif /* deprecated */
}