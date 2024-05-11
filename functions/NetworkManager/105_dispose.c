dispose(GObject *object)
{
    NMDeviceWifiP2P        *self = NM_DEVICE_WIFI_P2P(object);
    NMDeviceWifiP2PPrivate *priv = NM_DEVICE_WIFI_P2P_GET_PRIVATE(object);

    g_clear_object(&priv->sup_mgr);

    supplicant_interfaces_release(self, FALSE);

    G_OBJECT_CLASS(nm_device_wifi_p2p_parent_class)->dispose(object);
}