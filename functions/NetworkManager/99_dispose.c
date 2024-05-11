dispose(GObject *object)
{
    NMDeviceOvsInterface        *self = NM_DEVICE_OVS_INTERFACE(object);
    NMDeviceOvsInterfacePrivate *priv = NM_DEVICE_OVS_INTERFACE_GET_PRIVATE(self);

    nm_assert(!priv->wait_link.waiting);
    nm_assert(priv->wait_link.tun_link_signal_id == 0);
    nm_assert(!priv->wait_link.tun_set_ifindex_idle_source);

    if (priv->ovsdb) {
        g_signal_handlers_disconnect_by_func(priv->ovsdb, G_CALLBACK(ovsdb_ready), self);
        g_clear_object(&priv->ovsdb);
    }

    G_OBJECT_CLASS(nm_device_ovs_interface_parent_class)->dispose(object);
}