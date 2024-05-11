constructed(GObject *object)
{
    NMPolkitListener *self = NM_POLKIT_LISTENER(object);

    self->cancellable = g_cancellable_new();

    self->name_owner_changed_id =
        nm_dbus_connection_signal_subscribe_name_owner_changed(self->dbus_connection,
                                                               POLKIT_BUS_NAME,
                                                               name_owner_changed_cb,
                                                               self,
                                                               NULL);

    nm_dbus_connection_call_get_name_owner(self->dbus_connection,
                                           POLKIT_BUS_NAME,
                                           -1,
                                           self->cancellable,
                                           get_name_owner_cb,
                                           self);

    G_OBJECT_CLASS(nm_polkit_listener_parent_class)->constructed(object);
}