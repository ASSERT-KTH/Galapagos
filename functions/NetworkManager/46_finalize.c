finalize(GObject *object)
{
    NMDeviceVxlanPrivate *priv = NM_DEVICE_VXLAN_GET_PRIVATE(object);

    g_free(priv->group);
    g_free(priv->local);

    G_OBJECT_CLASS(nm_device_vxlan_parent_class)->finalize(object);
}