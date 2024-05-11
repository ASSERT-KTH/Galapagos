finalize(GObject *object)
{
    NMDeviceWifiP2P        *peer = NM_DEVICE_WIFI_P2P(object);
    NMDeviceWifiP2PPrivate *priv = NM_DEVICE_WIFI_P2P_GET_PRIVATE(peer);

    nm_assert(c_list_is_empty(&priv->peers_lst_head));

    G_OBJECT_CLASS(nm_device_wifi_p2p_parent_class)->finalize(object);
}