finalize(GObject *object)
{
    NMSettingOvsExternalIDs        *self = NM_SETTING_OVS_EXTERNAL_IDS(object);
    NMSettingOvsExternalIDsPrivate *priv = NM_SETTING_OVS_EXTERNAL_IDS_GET_PRIVATE(self);

    g_free(priv->data_keys);
    if (priv->data)
        g_hash_table_unref(priv->data);

    G_OBJECT_CLASS(nm_setting_ovs_external_ids_parent_class)->finalize(object);
}