dispose(GObject *object)
{
    NMSIfcfgRHStorage *self = NMS_IFCFG_RH_STORAGE(object);

    _storage_clear(self);

    G_OBJECT_CLASS(nms_ifcfg_rh_storage_parent_class)->dispose(object);
}