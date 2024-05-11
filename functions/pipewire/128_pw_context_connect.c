pw_context_connect(struct pw_context *context, struct pw_properties *properties,
	      size_t user_data_size)
{
	struct pw_core *core;
	int res;

	core = core_new(context, properties, user_data_size);
	if (core == NULL)
		return NULL;

	pw_log_debug("%p: connect", core);

	if ((res = pw_protocol_client_connect(core->conn,
					&core->properties->dict,
					NULL, NULL)) < 0)
		goto error_free;

	return core;

error_free:
	pw_core_disconnect(core);
	errno = -res;
	return NULL;
}