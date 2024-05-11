dispose(GObject *object)
{
    NMDhcpSystemdPrivate *priv = NM_DHCP_SYSTEMD_GET_PRIVATE(object);

    nm_clear_g_free(&priv->lease_file);

    if (priv->client6) {
        sd_dhcp6_client_stop(priv->client6);
        sd_dhcp6_client_unref(priv->client6);
        priv->client6 = NULL;
    }

    G_OBJECT_CLASS(nm_dhcp_systemd_parent_class)->dispose(object);
}