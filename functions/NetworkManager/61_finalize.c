finalize(GObject *object)
{
    NMSettingConnectionPrivate *priv = NM_SETTING_CONNECTION_GET_PRIVATE(object);

    nm_clear_pointer(&priv->permissions, g_array_unref);

    G_OBJECT_CLASS(nm_setting_connection_parent_class)->finalize(object);
}