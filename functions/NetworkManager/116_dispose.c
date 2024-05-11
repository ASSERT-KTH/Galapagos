dispose(GObject *object)
{
    NMDhcpDhcpcdPrivate *priv = NM_DHCP_DHCPCD_GET_PRIVATE(object);

    if (priv->dhcp_listener) {
        g_signal_handlers_disconnect_by_func(priv->dhcp_listener,
                                             G_CALLBACK(nm_dhcp_client_handle_event),
                                             NM_DHCP_DHCPCD(object));
        g_clear_object(&priv->dhcp_listener);
    }

    G_OBJECT_CLASS(nm_dhcp_dhcpcd_parent_class)->dispose(object);
}