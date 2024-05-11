dispose(GObject *object)
{
    NMSKeyfilePlugin        *self = NMS_KEYFILE_PLUGIN(object);
    NMSKeyfilePluginPrivate *priv = NMS_KEYFILE_PLUGIN_GET_PRIVATE(self);

    if (priv->config)
        g_signal_handlers_disconnect_by_func(priv->config, config_changed_cb, object);

    nm_sett_util_storages_clear(&priv->storages);

    nm_clear_g_free(&priv->dirname_libs[0]);
    nm_clear_g_free(&priv->dirname_etc);
    nm_clear_g_free(&priv->dirname_run);

    g_clear_object(&priv->config);

    G_OBJECT_CLASS(nms_keyfile_plugin_parent_class)->dispose(object);
}