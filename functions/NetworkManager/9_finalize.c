finalize(GObject *object)
{
    NMDeviceBtPrivate *priv = NM_DEVICE_BT_GET_PRIVATE(object);

    g_free(priv->connect_rfcomm_iface);
    g_free(priv->dbus_path);
    g_free(priv->name);
    g_free(priv->bdaddr);

    G_OBJECT_CLASS(nm_device_bt_parent_class)->finalize(object);
}