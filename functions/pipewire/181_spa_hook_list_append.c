static inline void spa_hook_list_append(struct spa_hook_list *list,
					struct spa_hook *hook,
					const void *funcs, void *data)
{
	spa_zero(*hook);
	hook->cb = SPA_CALLBACKS_INIT(funcs, data);
	spa_list_append(&list->list, &hook->link);
}