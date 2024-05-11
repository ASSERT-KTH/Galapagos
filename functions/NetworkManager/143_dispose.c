dispose(GObject *object)
{
    NMSIfcfgRHPlugin        *self = NMS_IFCFG_RH_PLUGIN(object);
    NMSIfcfgRHPluginPrivate *priv = NMS_IFCFG_RH_PLUGIN_GET_PRIVATE(self);

    if (priv->config)
        g_signal_handlers_disconnect_by_func(priv->config, config_changed_cb, self);

    /* FIXME(shutdown) we need a stop method so that we can unregistering the D-Bus service
     * when NMSettings is shutting down, and not when the instance gets destroyed. */
    _dbus_clear(self);

    nm_sett_util_storages_clear(&priv->storages);

    g_clear_object(&priv->config);

    G_OBJECT_CLASS(nms_ifcfg_rh_plugin_parent_class)->dispose(object);

    nm_clear_pointer(&priv->unmanaged_specs, g_hash_table_destroy);
    nm_clear_pointer(&priv->unrecognized_specs, g_hash_table_destroy);
}