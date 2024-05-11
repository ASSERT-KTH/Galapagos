dispose(GObject *object)
{
    NMAuthManager        *self = NM_AUTH_MANAGER(object);
    NMAuthManagerPrivate *priv = NM_AUTH_MANAGER_GET_PRIVATE(self);

    _LOGD("dispose");

    nm_assert(c_list_is_empty(&priv->calls_lst_head));

    priv->disposing = TRUE;

    nm_clear_g_cancellable(&priv->main_cancellable);

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->name_owner_changed_id);

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->changed_id);

    G_OBJECT_CLASS(nm_auth_manager_parent_class)->dispose(object);

    g_clear_object(&priv->dbus_connection);

    nm_clear_g_free(&priv->name_owner);
}