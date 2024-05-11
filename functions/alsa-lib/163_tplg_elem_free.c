void tplg_elem_free(struct tplg_elem *elem)
{
	list_del(&elem->list);

	tplg_ref_free_list(&elem->ref_list);

	/* free struct snd_tplg_ object,
	 * the union pointers share the same address
	 */
	if (elem->obj) {
		if (elem->free)
			elem->free(elem->obj);

		free(elem->obj);
	}

	free(elem);
}