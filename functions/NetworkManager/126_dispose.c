dispose(GObject *object)
{
    NMActiveConnection        *self = NM_ACTIVE_CONNECTION(object);
    NMActiveConnectionPrivate *priv = NM_ACTIVE_CONNECTION_GET_PRIVATE(self);

    nm_assert(!c_list_is_linked(&self->active_connections_lst));

    _LOGD("disposing");

    auth_complete(self, FALSE, "Authorization aborted");

    nm_clear_g_free(&priv->specific_object);

    _set_settings_connection(self, NULL);
    g_clear_object(&priv->applied_connection);

    _device_cleanup(self);

    if (priv->controller) {
        g_signal_handlers_disconnect_by_func(priv->controller, G_CALLBACK(master_state_cb), self);
    }
    g_clear_object(&priv->controller);

    if (priv->parent)
        unwatch_parent(self, TRUE);

    g_clear_object(&priv->subject);

    G_OBJECT_CLASS(nm_active_connection_parent_class)->dispose(object);
}