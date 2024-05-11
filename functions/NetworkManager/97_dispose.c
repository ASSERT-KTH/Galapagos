dispose(GObject *object)
{
    NMDevicePpp *self = NM_DEVICE_PPP(object);

    _ppp_mgr_cleanup(self);

    G_OBJECT_CLASS(nm_device_ppp_parent_class)->dispose(object);
}