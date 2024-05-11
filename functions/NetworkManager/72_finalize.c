finalize(GObject *object)
{
    NMSettingVpnPrivate *priv = NM_SETTING_VPN_GET_PRIVATE(object);

    nm_g_hash_table_unref(priv->data);
    nm_g_hash_table_unref(priv->secrets);

    G_OBJECT_CLASS(nm_setting_vpn_parent_class)->finalize(object);
}