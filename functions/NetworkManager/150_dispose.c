dispose(GObject *object)
{
    NMObject        *self = NM_OBJECT(object);
    NMObjectPrivate *priv = NM_OBJECT_GET_PRIVATE(self);

    if (!self->obj_base.is_disposing) {
        NML_DBUS_LOG(_NML_NMCLIENT_LOG_LEVEL_COERCE(NML_DBUS_LOG_LEVEL_TRACE),
                     "nmobj[" NM_HASH_OBFUSCATE_PTR_FMT "]: disposing",
                     NM_HASH_OBFUSCATE_PTR(self));
    }

    self->obj_base.is_disposing = TRUE;

    nm_assert(c_list_is_empty(&self->obj_base.queue_notify_lst));
    nm_assert(!priv->client);
    nm_assert(!priv->dbobj || !priv->dbobj->nmobj);

    clear_properties(self, NULL);

    G_OBJECT_CLASS(nm_object_parent_class)->dispose(object);

    nm_clear_pointer(&priv->dbobj, nml_dbus_object_unref);
}