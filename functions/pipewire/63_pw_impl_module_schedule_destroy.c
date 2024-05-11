void pw_impl_module_schedule_destroy(struct pw_impl_module *module)
{
	struct impl *impl = SPA_CONTAINER_OF(module, struct impl, this);

	if (impl->destroy_work_id != SPA_ID_INVALID)
		return;

	impl->destroy_work_id = pw_work_queue_add(pw_context_get_work_queue(module->context),
						  module, 0, do_destroy_module, NULL);
}