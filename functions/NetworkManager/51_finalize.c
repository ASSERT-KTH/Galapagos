finalize(GObject *object)
{
    NMIPConfigPrivate *priv = NM_IP_CONFIG_GET_PRIVATE(object);

    g_free(priv->gateway);

    g_ptr_array_unref(priv->routes);
    g_ptr_array_unref(priv->addresses);

    g_strfreev(priv->nameservers);
    g_strfreev(priv->domains);
    g_strfreev(priv->searches);
    g_strfreev(priv->wins_servers);

    G_OBJECT_CLASS(nm_ip_config_parent_class)->finalize(object);
}