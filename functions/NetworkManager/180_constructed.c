constructed(GObject *object)
{
    NMDeviceOlpcMesh        *self = NM_DEVICE_OLPC_MESH(object);
    NMDeviceOlpcMeshPrivate *priv = NM_DEVICE_OLPC_MESH_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_device_olpc_mesh_parent_class)->constructed(object);

    priv->manager = g_object_ref(NM_MANAGER_GET);

    g_signal_connect(priv->manager, NM_MANAGER_DEVICE_ADDED, G_CALLBACK(device_added_cb), self);
    g_signal_connect(priv->manager, NM_MANAGER_DEVICE_REMOVED, G_CALLBACK(device_removed_cb), self);
}