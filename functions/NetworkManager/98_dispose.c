dispose(GObject *object)
{
    NMDeviceWireGuard *self = NM_DEVICE_WIREGUARD(object);

    _device_cleanup(self);

    G_OBJECT_CLASS(nm_device_wireguard_parent_class)->dispose(object);
}