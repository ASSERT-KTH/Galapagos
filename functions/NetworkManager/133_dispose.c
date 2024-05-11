dispose(GObject *object)
{
    NMFirewalldManager        *self = NM_FIREWALLD_MANAGER(object);
    NMFirewalldManagerPrivate *priv = NM_FIREWALLD_MANAGER_GET_PRIVATE(self);

    /* as every pending operation takes a reference to the manager,
     * we don't expect pending operations at this point. */
    nm_assert(c_list_is_empty(&priv->pending_calls));

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->reloaded_id);
    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->name_owner_changed_id);

    nm_clear_g_cancellable(&priv->get_name_owner_cancellable);

    G_OBJECT_CLASS(nm_firewalld_manager_parent_class)->dispose(object);

    g_clear_object(&priv->dbus_connection);
}