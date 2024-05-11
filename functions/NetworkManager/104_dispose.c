dispose(GObject *object)
{
    NMDeviceOlpcMesh        *self = NM_DEVICE_OLPC_MESH(object);
    NMDeviceOlpcMeshPrivate *priv = NM_DEVICE_OLPC_MESH_GET_PRIVATE(self);

    companion_cleanup(self);

    if (priv->manager) {
        g_signal_handlers_disconnect_by_func(priv->manager, G_CALLBACK(device_added_cb), self);
        g_signal_handlers_disconnect_by_func(priv->manager, G_CALLBACK(device_removed_cb), self);
        g_clear_object(&priv->manager);
    }

    G_OBJECT_CLASS(nm_device_olpc_mesh_parent_class)->dispose(object);
}