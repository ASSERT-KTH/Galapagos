finalize(GObject *object)
{
    NMWifiP2PPeer        *self = NM_WIFI_P2P_PEER(object);
    NMWifiP2PPeerPrivate *priv = NM_WIFI_P2P_PEER_GET_PRIVATE(self);

    nm_assert(!self->wifi_device);
    nm_assert(c_list_is_empty(&self->peers_lst));

    nm_ref_string_unref(priv->supplicant_path);
    g_free(priv->name);
    g_free(priv->manufacturer);
    g_free(priv->model);
    g_free(priv->model_number);
    g_free(priv->serial);
    g_free(priv->address);
    g_bytes_unref(priv->wfd_ies);
    g_free(priv->groups);

    G_OBJECT_CLASS(nm_wifi_p2p_peer_parent_class)->finalize(object);
}