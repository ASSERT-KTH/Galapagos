dispose(GObject *object)
{
    NMDBusObject *self = NM_DBUS_OBJECT(object);

    /* Objects should have already been unexported by their owner, unless
     * we are quitting, where many objects stick around until exit.
     */
    if (self->internal.path) {
        if (!nm_dbus_manager_is_stopping(nm_dbus_object_get_manager(self)))
            g_warn_if_reached();
        nm_dbus_object_unexport(self);
    }

    G_OBJECT_CLASS(nm_dbus_object_parent_class)->dispose(object);

    g_clear_object(&self->internal.bus_manager);
}