int tplg_ref_add(struct tplg_elem *elem, int type, const char* id)
{
	struct tplg_ref *ref;

	ref = calloc(1, sizeof(*ref));
	if (!ref)
		return -ENOMEM;

	strncpy(ref->id, id, SNDRV_CTL_ELEM_ID_NAME_MAXLEN);
	ref->id[SNDRV_CTL_ELEM_ID_NAME_MAXLEN - 1] = 0;
	ref->type = type;

	list_add_tail(&ref->list, &elem->ref_list);
	return 0;
}