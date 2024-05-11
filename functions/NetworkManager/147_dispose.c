dispose(GObject *object)
{
    NMSKeyfileStorage *self = NMS_KEYFILE_STORAGE(object);

    _storage_clear(self);

    G_OBJECT_CLASS(nms_keyfile_storage_parent_class)->dispose(object);
}