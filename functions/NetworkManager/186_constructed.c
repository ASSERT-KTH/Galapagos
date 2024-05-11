constructed(GObject *object)
{
    NMDBusObjectClass *klass;

    G_OBJECT_CLASS(nm_dbus_object_parent_class)->constructed(object);

    klass = NM_DBUS_OBJECT_GET_CLASS(object);

    if (klass->export_on_construction)
        nm_dbus_object_export((NMDBusObject *) object);

    /* NMDBusObject types should be very careful when overwriting notify().
     * It is possible to do, but this is a reminder that it's probably not
     * a good idea.
     *
     * It's not a good idea, because NMDBusObject uses dispatch_properties_changed()
     * to emit signals about a bunch of property changes. So, we want to make
     * use of g_object_freeze_notify() / g_object_thaw_notify() to combine multiple
     * property changes in one signal on D-Bus. Note that notify() is not invoked
     * while the signal is frozen, that means, whatever you do inside notify()
     * will not make it into the same batch of PropertiesChanged signal. That is
     * confusing, and probably not what you want.
     *
     * Simple solution: don't overwrite notify(). */
    nm_assert(!G_OBJECT_CLASS(klass)->notify);
}