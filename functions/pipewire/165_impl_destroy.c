static void impl_destroy(struct impl *impl)
{
	if (impl->core && impl->do_disconnect)
		pw_core_disconnect(impl->core);
	pw_properties_free(impl->props);
	free(impl);
}