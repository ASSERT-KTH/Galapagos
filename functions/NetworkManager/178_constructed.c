constructed(GObject *object)
{
    NMDevice        *self = NM_DEVICE(object);
    NMDevicePrivate *priv = NM_DEVICE_GET_PRIVATE(self);
    NMPlatform      *platform;

    if (NM_DEVICE_GET_CLASS(self)->get_generic_capabilities)
        priv->capabilities |= NM_DEVICE_GET_CLASS(self)->get_generic_capabilities(self);

    platform = nm_device_get_platform(self);
    g_signal_connect(platform, NM_PLATFORM_SIGNAL_LINK_CHANGED, G_CALLBACK(link_changed_cb), self);

    priv->manager  = g_object_ref(NM_MANAGER_GET);
    priv->settings = g_object_ref(NM_SETTINGS_GET);

    g_signal_connect(priv->settings,
                     NM_SETTINGS_SIGNAL_CONNECTION_ADDED,
                     G_CALLBACK(cp_connection_added),
                     self);
    g_signal_connect(priv->settings,
                     NM_SETTINGS_SIGNAL_CONNECTION_UPDATED,
                     G_CALLBACK(cp_connection_updated),
                     self);
    g_signal_connect(priv->settings,
                     NM_SETTINGS_SIGNAL_CONNECTION_REMOVED,
                     G_CALLBACK(cp_connection_removed),
                     self);

    G_OBJECT_CLASS(nm_device_parent_class)->constructed(object);

    _LOGD(LOGD_DEVICE, "constructed (%s)", G_OBJECT_TYPE_NAME(self));
}