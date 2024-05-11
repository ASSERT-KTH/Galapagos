finalize(GObject *object)
{
    NMSettingWirelessPrivate *priv = NM_SETTING_WIRELESS_GET_PRIVATE(object);

    g_free(priv->cloned_mac_address);
    nm_g_ptr_array_unref(priv->seen_bssids);

    G_OBJECT_CLASS(nm_setting_wireless_parent_class)->finalize(object);
}