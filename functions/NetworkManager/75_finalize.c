finalize(GObject *object)
{
    NMSettingWirelessSecurity        *self = NM_SETTING_WIRELESS_SECURITY(object);
    NMSettingWirelessSecurityPrivate *priv = NM_SETTING_WIRELESS_SECURITY_GET_PRIVATE(self);

    g_slist_free_full(priv->proto, g_free);
    g_slist_free_full(priv->pairwise, g_free);
    g_slist_free_full(priv->group, g_free);

    G_OBJECT_CLASS(nm_setting_wireless_security_parent_class)->finalize(object);
}