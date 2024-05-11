finalize(GObject *object)
{
    NMDeviceEthernetPrivate *priv = NM_DEVICE_ETHERNET_GET_PRIVATE(object);

    g_free(priv->perm_hw_address);
    g_strfreev(priv->s390_subchannels);

    G_OBJECT_CLASS(nm_device_ethernet_parent_class)->finalize(object);
}