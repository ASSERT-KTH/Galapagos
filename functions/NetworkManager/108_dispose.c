dispose(GObject *object)
{
    NMDeviceModemPrivate *priv = NM_DEVICE_MODEM_GET_PRIVATE(object);

    if (priv->modem) {
        g_signal_handlers_disconnect_by_data(priv->modem, NM_DEVICE_MODEM(object));
        nm_clear_pointer(&priv->modem, nm_modem_unclaim);
    }

    nm_clear_g_free(&priv->device_id);
    nm_clear_g_free(&priv->operator_code);
    nm_clear_g_free(&priv->apn);

    G_OBJECT_CLASS(nm_device_modem_parent_class)->dispose(object);
}