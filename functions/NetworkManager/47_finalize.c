finalize(GObject *object)
{
    NMDeviceWifiPrivate *priv = NM_DEVICE_WIFI_GET_PRIVATE(object);

    g_free(priv->perm_hw_address);

    G_OBJECT_CLASS(nm_device_wifi_parent_class)->finalize(object);
}