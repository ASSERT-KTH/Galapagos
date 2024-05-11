void pw_impl_module_destroy(struct pw_impl_module *module)
{
	struct impl *impl = SPA_CONTAINER_OF(module, struct impl, this);

	pw_log_debug("%p: destroy %s", module, module->info.name);
	pw_impl_module_emit_destroy(module);

	spa_list_remove(&module->link);

	if (module->global) {
		spa_hook_remove(&module->global_listener);
		pw_global_destroy(module->global);
	}

	pw_log_debug("%p: free", module);
	pw_impl_module_emit_free(module);
	free((char *) module->info.name);
	free((char *) module->info.filename);
	free((char *) module->info.args);

	pw_properties_free(module->properties);

	spa_hook_list_clean(&module->listener_list);

	if (impl->destroy_work_id != SPA_ID_INVALID)
		pw_work_queue_cancel(pw_context_get_work_queue(module->context),
				     module, SPA_ID_INVALID);

	if (pw_should_dlclose() && dlclose(impl->hnd) != 0)
		pw_log_warn("%p: dlclose failed: %s", module, dlerror());
	free(impl);
}