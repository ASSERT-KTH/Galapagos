int pw_impl_module_update_properties(struct pw_impl_module *module, const struct spa_dict *dict)
{
	struct pw_resource *resource;
	int changed;

	changed = pw_properties_update(module->properties, dict);
	module->info.props = &module->properties->dict;

	pw_log_debug("%p: updated %d properties", module, changed);

	if (!changed)
		return 0;

	module->info.change_mask |= PW_MODULE_CHANGE_MASK_PROPS;
	if (module->global)
		spa_list_for_each(resource, &module->global->resource_list, link)
			pw_module_resource_info(resource, &module->info);
	module->info.change_mask = 0;

	return changed;
}