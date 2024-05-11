finalize(GObject *object)
{
    NMWifiAP        *self = NM_WIFI_AP(object);
    NMWifiAPPrivate *priv = NM_WIFI_AP_GET_PRIVATE(self);

    nm_assert(!self->wifi_device);
    nm_assert(c_list_is_empty(&self->aps_lst));

    nm_ref_string_unref(self->_supplicant_path);
    if (priv->ssid)
        g_bytes_unref(priv->ssid);
    g_free(priv->address);

    G_OBJECT_CLASS(nm_wifi_ap_parent_class)->finalize(object);
}