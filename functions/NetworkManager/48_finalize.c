finalize(GObject *object)
{
    NMDeviceWireGuardPrivate *priv = NM_DEVICE_WIREGUARD_GET_PRIVATE(object);

    g_bytes_unref(priv->public_key);

    G_OBJECT_CLASS(nm_device_wireguard_parent_class)->finalize(object);
}