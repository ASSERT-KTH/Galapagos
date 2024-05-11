finalize(GObject *object)
{
    NMSettingUser        *self = NM_SETTING_USER(object);
    NMSettingUserPrivate *priv = NM_SETTING_USER_GET_PRIVATE(self);

    g_free(priv->keys);
    if (priv->data)
        g_hash_table_unref(priv->data);
    if (priv->data_invalid)
        g_hash_table_unref(priv->data_invalid);

    G_OBJECT_CLASS(nm_setting_user_parent_class)->finalize(object);
}