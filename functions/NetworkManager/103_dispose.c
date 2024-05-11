dispose(GObject *object)
{
    NMDeviceIwd        *self = NM_DEVICE_IWD(object);
    NMDeviceIwdPrivate *priv = NM_DEVICE_IWD_GET_PRIVATE(self);

    nm_clear_g_cancellable(&priv->cancellable);

    g_signal_handlers_disconnect_by_func(self, autoconnect_changed, self);
    nm_device_iwd_set_dbus_object(self, NULL);

    G_OBJECT_CLASS(nm_device_iwd_parent_class)->dispose(object);

    nm_assert(c_list_is_empty(&priv->aps_lst_head));

    g_clear_object(&priv->manager);
}