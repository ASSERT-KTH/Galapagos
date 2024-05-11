dispose(GObject *object)
{
    NMDhcpClient        *self = NM_DHCP_CLIENT(object);
    NMDhcpClientPrivate *priv = NM_DHCP_CLIENT_GET_PRIVATE(self);

    nm_dhcp_client_stop(self, FALSE);

    watch_cleanup(self);

    nm_clear_g_source_inst(&priv->previous_lease_timeout_source);
    nm_clear_g_source_inst(&priv->no_lease_timeout_source);

    if (!NM_IS_IPv4(priv->config.addr_family)) {
        nm_clear_g_source_inst(&priv->v6.lladdr_timeout_source);
        nm_clear_g_source_inst(&priv->v6.dad_timeout_source);
    }

    nm_clear_pointer(&priv->effective_client_id, g_bytes_unref);

    nm_assert(!priv->watch_source);
    nm_assert(!priv->l3cd_next);
    nm_assert(!priv->l3cd_curr);
    nm_assert(priv->l3cfg_notify.id == 0);

    G_OBJECT_CLASS(nm_dhcp_client_parent_class)->dispose(object);
}