finalize(GObject *object)
{
    NMIPConfig        *self = NM_IP_CONFIG(object);
    NMIPConfigPrivate *priv = NM_IP_CONFIG_GET_PRIVATE(self);

    nm_clear_g_source_inst(&priv->notify_platform_timeout_source);

    nm_clear_g_signal_handler(priv->l3cfg, &priv->l3cfg_notify_id);

    g_object_unref(priv->l3cfg);

    nm_g_variant_unref(priv->v_address_data);
    nm_g_variant_unref(priv->v_addresses);
    nm_g_variant_unref(priv->v_route_data);
    nm_g_variant_unref(priv->v_routes);

    nmp_object_unref(priv->v_gateway.best_default_route);

    nm_l3_config_data_unref(priv->l3cd);

    G_OBJECT_CLASS(nm_ip_config_parent_class)->finalize(object);
}