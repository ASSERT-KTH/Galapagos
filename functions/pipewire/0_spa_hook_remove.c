static inline void spa_hook_remove(struct spa_hook *hook)
{
	if (spa_list_is_initialized(&hook->link))
		spa_list_remove(&hook->link);
	if (hook->removed)
		hook->removed(hook);
}