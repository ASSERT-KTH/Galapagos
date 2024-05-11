dispose(GObject *object)
{
    NMDeviceEthernet        *self = NM_DEVICE_ETHERNET(object);
    NMDeviceEthernetPrivate *priv = NM_DEVICE_ETHERNET_GET_PRIVATE(self);

    wired_secrets_cancel(self);

    supplicant_interface_release(self);

    nm_clear_g_source_inst(&priv->ppp_data.wait_source);

    nm_clear_g_source(&priv->dcb_timeout_id);

    nm_clear_g_signal_handler(self, &priv->carrier_id);

    G_OBJECT_CLASS(nm_device_ethernet_parent_class)->dispose(object);
}