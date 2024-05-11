constructed(GObject *object)
{
    NMIPConfig        *self = NM_IP_CONFIG(object);
    NMIPConfigPrivate *priv = NM_IP_CONFIG_GET_PRIVATE(self);

    priv->l3cfg_notify_id =
        g_signal_connect(priv->l3cfg, NM_L3CFG_SIGNAL_NOTIFY, G_CALLBACK(_l3cfg_notify_cb), self);

    priv->l3cd = nm_l3_config_data_ref(nm_l3cfg_get_combined_l3cd(priv->l3cfg, TRUE));

    _handle_platform_change(self, ~((guint32) 0u), TRUE);

    G_OBJECT_CLASS(nm_ip_config_parent_class)->constructed(object);
}