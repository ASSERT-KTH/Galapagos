finalize(GObject *object)
{
    NMDeviceModemPrivate *priv = NM_DEVICE_MODEM_GET_PRIVATE(object);

    g_free(priv->device_id);
    g_free(priv->operator_code);
    g_free(priv->apn);

    G_OBJECT_CLASS(nm_device_modem_parent_class)->finalize(object);
}