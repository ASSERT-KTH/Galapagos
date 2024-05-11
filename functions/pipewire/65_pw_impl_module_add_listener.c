void pw_impl_module_add_listener(struct pw_impl_module *module,
			    struct spa_hook *listener,
			    const struct pw_impl_module_events *events,
			    void *data)
{
	spa_hook_list_append(&module->listener_list, listener, events, data);
}