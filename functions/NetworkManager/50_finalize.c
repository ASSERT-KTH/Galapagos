finalize(GObject *object)
{
    NMDhcpConfigPrivate *priv = NM_DHCP_CONFIG_GET_PRIVATE(object);

    g_hash_table_destroy(priv->options);

    G_OBJECT_CLASS(nm_dhcp_config_parent_class)->finalize(object);
}