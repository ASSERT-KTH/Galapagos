finalize(GObject *object)
{
    NMSettingIPConfig        *self = NM_SETTING_IP_CONFIG(object);
    NMSettingIPConfigPrivate *priv = NM_SETTING_IP_CONFIG_GET_PRIVATE(self);

    nm_g_ptr_array_unref(priv->dns);
    g_ptr_array_unref(priv->addresses);
    g_ptr_array_unref(priv->routes);
    nm_g_ptr_array_unref(priv->routing_rules);

    G_OBJECT_CLASS(nm_setting_ip_config_parent_class)->finalize(object);
}