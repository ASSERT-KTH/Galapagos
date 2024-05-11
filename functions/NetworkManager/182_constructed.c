constructed(GObject *object)
{
    NMDeviceWifi        *self = NM_DEVICE_WIFI(object);
    NMDeviceWifiPrivate *priv = NM_DEVICE_WIFI_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_device_wifi_parent_class)->constructed(object);

    if (priv->capabilities & _NM_WIFI_DEVICE_CAP_AP)
        _LOGI(LOGD_PLATFORM | LOGD_WIFI, "driver supports Access Point (AP) mode");

    /* Connect to the supplicant manager */
    priv->sup_mgr = g_object_ref(nm_supplicant_manager_get());
}