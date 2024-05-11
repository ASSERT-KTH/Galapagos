static void impl_destroy(struct module_roc_source_data *data)
{
	if (data->playback)
		pw_stream_destroy(data->playback);
	if (data->core && data->do_disconnect)
		pw_core_disconnect(data->core);

	pw_properties_free(data->playback_props);

	spa_clear_ptr(data->receiver, roc_receiver_close);
	spa_clear_ptr(data->context, roc_context_close);

	spa_clear_ptr(data->local_source_addr, roc_endpoint_deallocate);
	spa_clear_ptr(data->local_repair_addr, roc_endpoint_deallocate);
	spa_clear_ptr(data->local_control_addr, roc_endpoint_deallocate);

	free(data->local_ip);
	free(data);
}