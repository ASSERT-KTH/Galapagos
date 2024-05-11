finalize(GObject *object)
{
    NMDhcpClient        *self = NM_DHCP_CLIENT(object);
    NMDhcpClientPrivate *priv = NM_DHCP_CLIENT_GET_PRIVATE(self);

    config_clear(&priv->config);

    G_OBJECT_CLASS(nm_dhcp_client_parent_class)->finalize(object);
}