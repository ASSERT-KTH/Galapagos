nm_device_get_ip_iface(NMDevice *self)
{
    NMDevicePrivate *priv;

    g_return_val_if_fail(self != NULL, NULL);

    priv = NM_DEVICE_GET_PRIVATE(self);
    /* If it's not set, default to iface */
    return priv->ip_iface ?: priv->iface;
}