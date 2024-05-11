dispose(GObject *object)
{
    NMDhcpDhclientPrivate *priv = NM_DHCP_DHCLIENT_GET_PRIVATE(object);

    if (priv->dhcp_listener) {
        g_signal_handlers_disconnect_by_func(priv->dhcp_listener,
                                             G_CALLBACK(nm_dhcp_client_handle_event),
                                             NM_DHCP_DHCLIENT(object));
        g_clear_object(&priv->dhcp_listener);
    }

    nm_clear_g_free(&priv->pid_file);
    nm_clear_g_free(&priv->conf_file);
    nm_clear_g_free(&priv->lease_file);

    G_OBJECT_CLASS(nm_dhcp_dhclient_parent_class)->dispose(object);
}