finalize(GObject *object)
{
    NMDeviceWifi        *self = NM_DEVICE_WIFI(object);
    NMDeviceWifiPrivate *priv = NM_DEVICE_WIFI_GET_PRIVATE(self);

    nm_assert(c_list_is_empty(&priv->aps_lst_head));
    nm_assert(g_hash_table_size(priv->aps_idx_by_supplicant_path) == 0);

    g_hash_table_unref(priv->aps_idx_by_supplicant_path);

    G_OBJECT_CLASS(nm_device_wifi_parent_class)->finalize(object);
}