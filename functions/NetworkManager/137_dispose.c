dispose(GObject *object)
{
    NMPacrunnerManagerPrivate *priv = NM_PACRUNNER_MANAGER_GET_PRIVATE(object);

    nm_assert(c_list_is_empty(&priv->conf_id_lst_head));

    /* we cancel all pending operations. Note that pacrunner automatically
     * removes all configuration once NetworkManager disconnects from
     * the bus -- which happens soon after we destroy the pacrunner manager.
     */
    nm_clear_g_cancellable(&priv->cancellable);

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->name_owner_changed_id);
    g_clear_object(&priv->dbus_connection);

    G_OBJECT_CLASS(nm_pacrunner_manager_parent_class)->dispose(object);
}