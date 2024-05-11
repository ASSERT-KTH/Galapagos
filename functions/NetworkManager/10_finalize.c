finalize(GObject *object)
{
    NMDeviceEthernet        *self = NM_DEVICE_ETHERNET(object);
    NMDeviceEthernetPrivate *priv = NM_DEVICE_ETHERNET_GET_PRIVATE(self);

    g_clear_object(&priv->supplicant.mgr);
    g_free(priv->subchan1);
    g_free(priv->subchan2);
    g_free(priv->subchan3);
    g_free(priv->subchannels);
    g_strfreev(priv->subchannels_dbus);
    g_free(priv->s390_nettype);
    g_hash_table_destroy(priv->s390_options);

    G_OBJECT_CLASS(nm_device_ethernet_parent_class)->finalize(object);
}