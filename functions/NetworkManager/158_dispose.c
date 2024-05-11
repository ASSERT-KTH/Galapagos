dispose(GObject *object)
{
    NMPolkitListener *self = NM_POLKIT_LISTENER(object);
    AuthRequest      *request;

    nm_clear_g_cancellable(&self->cancellable);

    while ((request = c_list_first_entry(&self->request_lst_head, AuthRequest, request_lst)))
        auth_request_complete(request, FALSE);

    if (self->dbus_connection) {
        nm_clear_g_dbus_connection_signal(self->dbus_connection, &self->name_owner_changed_id);
        g_dbus_connection_unregister_object(self->dbus_connection, self->pk_auth_agent_reg_id);
        agent_unregister(self);
        nm_clear_g_free(&self->name_owner);
        g_clear_object(&self->dbus_connection);
    }

    nm_clear_pointer(&self->main_context, g_main_context_unref);

    G_OBJECT_CLASS(nm_polkit_listener_parent_class)->dispose(object);
}