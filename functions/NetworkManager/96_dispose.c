dispose(GObject *object)
{
    NMDeviceMacsec *self = NM_DEVICE_MACSEC(object);

    macsec_secrets_cancel(self);
    supplicant_interface_release(self);

    G_OBJECT_CLASS(nm_device_macsec_parent_class)->dispose(object);

    nm_assert(NM_DEVICE_MACSEC_GET_PRIVATE(self)->parent_mtu_id == 0);
}