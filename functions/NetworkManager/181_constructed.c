constructed(GObject *object)
{
    NMDeviceWifiP2P *self = NM_DEVICE_WIFI_P2P(object);

    G_OBJECT_CLASS(nm_device_wifi_p2p_parent_class)->constructed(object);

    _set_is_waiting_for_supplicant(self, TRUE);
}