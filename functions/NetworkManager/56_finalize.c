finalize(GObject *object)
{
    NMWifiP2PPeerPrivate *priv = NM_WIFI_P2P_PEER_GET_PRIVATE(object);

    g_free(priv->name);
    g_free(priv->manufacturer);
    g_free(priv->model);
    g_free(priv->model_number);
    g_free(priv->serial);
    g_free(priv->hw_address);

    g_bytes_unref(priv->wfd_ies);

    G_OBJECT_CLASS(nm_wifi_p2p_peer_parent_class)->finalize(object);
}