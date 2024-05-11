dispose(GObject *object)
{
    NMDhcpListenerPrivate *priv = NM_DHCP_LISTENER_GET_PRIVATE(object);

    nm_clear_g_signal_handler(priv->dbus_mgr, &priv->new_conn_id);
    nm_clear_g_signal_handler(priv->dbus_mgr, &priv->dis_conn_id);

    nm_clear_pointer(&priv->connections, g_hash_table_destroy);

    g_clear_object(&priv->dbus_mgr);

    G_OBJECT_CLASS(nm_dhcp_listener_parent_class)->dispose(object);
}