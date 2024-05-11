finalize(GObject *object)
{
    NMSettingWiredPrivate *priv = NM_SETTING_WIRED_GET_PRIVATE(object);

    _s390_options_clear(priv);

    g_free(priv->cloned_mac_address);
    g_strfreev(priv->s390_subchannels);

    G_OBJECT_CLASS(nm_setting_wired_parent_class)->finalize(object);
}