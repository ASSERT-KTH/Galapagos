finalize(GObject *object)
{
    NMDhcpConfigPrivate *priv = NM_DHCP_CONFIG_GET_PRIVATE(object);

    g_variant_unref(priv->options);

    nm_l3_config_data_unref(priv->l3cd);

    G_OBJECT_CLASS(nm_dhcp_config_parent_class)->finalize(object);
}