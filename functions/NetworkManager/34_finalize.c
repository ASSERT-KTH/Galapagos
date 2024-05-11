finalize(GObject *object)
{
    NMAccessPointPrivate *priv = NM_ACCESS_POINT_GET_PRIVATE(object);

    if (priv->ssid)
        g_bytes_unref(priv->ssid);
    g_free(priv->bssid);

    G_OBJECT_CLASS(nm_access_point_parent_class)->finalize(object);
}