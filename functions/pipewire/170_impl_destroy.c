static void impl_destroy(struct module_roc_sink_data *data)
{
	if (data->capture)
		pw_stream_destroy(data->capture);
	if (data->core && data->do_disconnect)
		pw_core_disconnect(data->core);

	pw_properties_free(data->capture_props);

	spa_clear_ptr(data->sender, roc_sender_close);
	spa_clear_ptr(data->context, roc_context_close);

	spa_clear_ptr(data->remote_source_addr, roc_endpoint_deallocate);
	spa_clear_ptr(data->remote_repair_addr, roc_endpoint_deallocate);
	spa_clear_ptr(data->remote_control_addr, roc_endpoint_deallocate);

	free(data->remote_ip);
	free(data);
}