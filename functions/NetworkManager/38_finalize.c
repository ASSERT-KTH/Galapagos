finalize(GObject *object)
{
    NMDeviceGenericPrivate *priv = NM_DEVICE_GENERIC_GET_PRIVATE(object);

    g_free(priv->type_description);

    G_OBJECT_CLASS(nm_device_generic_parent_class)->finalize(object);
}