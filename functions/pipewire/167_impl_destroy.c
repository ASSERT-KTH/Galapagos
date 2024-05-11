static void impl_destroy(struct pw_protocol_client *client)
{
	struct client *impl = SPA_CONTAINER_OF(client, struct client, this);

	impl_disconnect(client);

	if (impl->connection)
                pw_protocol_native_connection_destroy(impl->connection);
	impl->connection = NULL;

	spa_list_remove(&client->link);
	client_unref(impl);
}