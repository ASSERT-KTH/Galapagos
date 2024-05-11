finalize(GObject *object)
{
    NMSetting        *self = NM_SETTING(object);
    NMSettingPrivate *priv = NM_SETTING_GET_PRIVATE(self);

    if (priv->gendata) {
        g_free(priv->gendata->names);
        g_free(priv->gendata->values);
        g_hash_table_unref(priv->gendata->hash);
        g_slice_free(GenData, priv->gendata);
    }

    G_OBJECT_CLASS(nm_setting_parent_class)->finalize(object);

    _finalize_direct(self);
}