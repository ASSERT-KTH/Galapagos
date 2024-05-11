constructed(GObject *object)
{
    NMSKeyfilePlugin        *self = NMS_KEYFILE_PLUGIN(object);
    NMSKeyfilePluginPrivate *priv = NMS_KEYFILE_PLUGIN_GET_PRIVATE(self);

    G_OBJECT_CLASS(nms_keyfile_plugin_parent_class)->constructed(object);

    if (nm_config_data_has_value(nm_config_get_data_orig(priv->config),
                                 NM_CONFIG_KEYFILE_GROUP_KEYFILE,
                                 NM_CONFIG_KEYFILE_KEY_KEYFILE_HOSTNAME,
                                 NM_CONFIG_GET_VALUE_RAW))
        _LOGW("'hostname' option is deprecated and has no effect");

    if (nm_config_data_has_value(nm_config_get_data_orig(priv->config),
                                 NM_CONFIG_KEYFILE_GROUP_MAIN,
                                 NM_CONFIG_KEYFILE_KEY_MAIN_MONITOR_CONNECTION_FILES,
                                 NM_CONFIG_GET_VALUE_RAW))
        _LOGW("'monitor-connection-files' option is deprecated and has no effect");

    g_signal_connect(G_OBJECT(priv->config),
                     NM_CONFIG_SIGNAL_CONFIG_CHANGED,
                     G_CALLBACK(config_changed_cb),
                     self);
}