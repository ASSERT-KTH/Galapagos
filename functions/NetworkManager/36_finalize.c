finalize(GObject *object)
{
    NMDeviceBtPrivate *priv = NM_DEVICE_BT_GET_PRIVATE(object);

    g_free(priv->name);

    G_OBJECT_CLASS(nm_device_bt_parent_class)->finalize(object);
}