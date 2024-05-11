finalize(GObject *object)
{
    NMDeviceMacsecPrivate *priv = NM_DEVICE_MACSEC_GET_PRIVATE(object);

    g_free(priv->validation);

    G_OBJECT_CLASS(nm_device_macsec_parent_class)->finalize(object);
}