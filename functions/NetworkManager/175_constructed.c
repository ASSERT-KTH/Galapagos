constructed(GObject *object)
{
    NMDeviceAdsl        *self = NM_DEVICE_ADSL(object);
    NMDeviceAdslPrivate *priv = NM_DEVICE_ADSL_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_device_adsl_parent_class)->constructed(object);

    priv->carrier_poll_id = g_timeout_add_seconds(5, carrier_update_cb, self);

    _LOGD(LOGD_ADSL, "ATM device index %d", priv->atm_index);

    g_return_if_fail(priv->atm_index >= 0);
}