constructed(GObject *object)
{
    NMSIfcfgRHPlugin        *self = NMS_IFCFG_RH_PLUGIN(object);
    NMSIfcfgRHPluginPrivate *priv = NMS_IFCFG_RH_PLUGIN_GET_PRIVATE(self);

    G_OBJECT_CLASS(nms_ifcfg_rh_plugin_parent_class)->constructed(object);

    g_signal_connect(priv->config,
                     NM_CONFIG_SIGNAL_CONFIG_CHANGED,
                     G_CALLBACK(config_changed_cb),
                     self);

    _dbus_setup(self);
}