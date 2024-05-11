dispose(GObject *object)
{
    NMDhcpDhcpcanonPrivate *priv = NM_DHCP_DHCPCANON_GET_PRIVATE(object);

    if (priv->dhcp_listener) {
        g_signal_handlers_disconnect_by_func(priv->dhcp_listener,
                                             G_CALLBACK(nm_dhcp_client_handle_event),
                                             NM_DHCP_DHCPCANON(object));
        g_clear_object(&priv->dhcp_listener);
    }

    nm_clear_g_free(&priv->pid_file);

    G_OBJECT_CLASS(nm_dhcp_dhcpcanon_parent_class)->dispose(object);
}