nm_device_get_ip_ifindex(const NMDevice *self)
{
    const NMDevicePrivate *priv;

    g_return_val_if_fail(self != NULL, 0);

    priv = NM_DEVICE_GET_PRIVATE(self);
    /* If it's not set, default to ifindex */
    return priv->ip_iface ? priv->ip_ifindex : priv->ifindex;
}