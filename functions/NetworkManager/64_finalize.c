finalize(GObject *object)
{
    NMSettingOvsOtherConfig        *self = NM_SETTING_OVS_OTHER_CONFIG(object);
    NMSettingOvsOtherConfigPrivate *priv = NM_SETTING_OVS_OTHER_CONFIG_GET_PRIVATE(self);

    g_free(priv->data_keys);
    if (priv->data)
        g_hash_table_unref(priv->data);

    G_OBJECT_CLASS(nm_setting_ovs_other_config_parent_class)->finalize(object);
}