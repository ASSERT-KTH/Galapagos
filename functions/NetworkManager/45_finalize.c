finalize(GObject *object)
{
    NMDeviceTunPrivate *priv = NM_DEVICE_TUN_GET_PRIVATE(object);

    g_free(priv->mode);

    G_OBJECT_CLASS(nm_device_tun_parent_class)->finalize(object);
}