nm_device_get_applied_connection(NMDevice *self)
{
    NMDevicePrivate *priv;

    g_return_val_if_fail(NM_IS_DEVICE(self), NULL);

    priv = NM_DEVICE_GET_PRIVATE(self);

    return priv->act_request.obj ? nm_act_request_get_applied_connection(priv->act_request.obj)
                                 : NULL;
}