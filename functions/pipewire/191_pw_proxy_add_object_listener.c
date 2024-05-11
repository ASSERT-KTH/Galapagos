void pw_proxy_add_object_listener(struct pw_proxy *proxy,
				 struct spa_hook *listener,
				 const void *funcs,
				 void *data)
{
	spa_hook_list_append(&proxy->object_listener_list, listener, funcs, data);
}