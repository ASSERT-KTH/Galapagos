void pw_deinit(void)
{
	struct support *support = &global_support;
	struct registry *registry = &support->registry;
	struct handle *h;

	pthread_mutex_lock(&init_lock);
	if (support->init_count == 0)
		goto done;
	if (--support->init_count > 0)
		goto done;

	pthread_mutex_lock(&support_lock);
	pw_log_deinit();

	spa_list_consume(h, &registry->handles, link)
		unref_handle(h);

	free(support->i18n_domain);
	spa_zero(global_support);
	pthread_mutex_unlock(&support_lock);
done:
	pthread_mutex_unlock(&init_lock);

}