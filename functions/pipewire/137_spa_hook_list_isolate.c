spa_hook_list_isolate(struct spa_hook_list *list,
		struct spa_hook_list *save,
		struct spa_hook *hook,
		const void *funcs, void *data)
{
	/* init save list and move hooks to it */
	spa_hook_list_init(save);
	spa_list_insert_list(&save->list, &list->list);
	/* init hooks and add single hook */
	spa_hook_list_init(list);
	spa_hook_list_append(list, hook, funcs, data);
}