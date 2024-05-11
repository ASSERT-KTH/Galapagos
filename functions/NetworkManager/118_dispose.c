dispose(GObject *object)
{
    NMDhcpNettoolsPrivate *priv = NM_DHCP_NETTOOLS_GET_PRIVATE(object);

    nm_clear_g_free(&priv->lease_file);
    nm_clear_g_source_inst(&priv->event_source);
    nm_clear_g_source_inst(&priv->pop_all_events_on_idle_source);
    nm_clear_pointer(&priv->granted.lease, n_dhcp4_client_lease_unref);
    nm_clear_l3cd(&priv->granted.lease_l3cd);
    nm_clear_pointer(&priv->probe, n_dhcp4_client_probe_free);
    nm_clear_pointer(&priv->client, n_dhcp4_client_unref);

    G_OBJECT_CLASS(nm_dhcp_nettools_parent_class)->dispose(object);
}