finalize(GObject *object)
{
    NMDeviceHsrPrivate *priv = NM_DEVICE_HSR_GET_PRIVATE(object);

    g_free(priv->supervision_address);

    G_OBJECT_CLASS(nm_device_hsr_parent_class)->finalize(object);
}