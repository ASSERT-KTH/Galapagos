finalize(GObject *object)
{
    NMDeviceMacvlanPrivate *priv = NM_DEVICE_MACVLAN_GET_PRIVATE(object);

    g_free(priv->mode);

    G_OBJECT_CLASS(nm_device_macvlan_parent_class)->finalize(object);
}