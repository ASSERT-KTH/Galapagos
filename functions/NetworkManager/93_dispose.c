dispose(GObject *object)
{
    NMDeviceBt        *self = NM_DEVICE_BT(object);
    NMDeviceBtPrivate *priv = NM_DEVICE_BT_GET_PRIVATE(self);

    nm_clear_g_signal_handler(nm_device_get_platform(NM_DEVICE(self)),
                              &priv->connect_watch_link_id);
    nm_clear_g_source(&priv->connect_watch_link_idle_id);

    nm_clear_g_source(&priv->connect_wait_modem_id);
    nm_clear_g_cancellable(&priv->connect_bz_cancellable);

    if (priv->modem_manager) {
        g_signal_handlers_disconnect_by_func(priv->modem_manager,
                                             G_CALLBACK(mm_name_owner_changed_cb),
                                             self);
        g_signal_handlers_disconnect_by_func(priv->modem_manager,
                                             G_CALLBACK(mm_modem_added_cb),
                                             self);
        nm_modem_manager_name_owner_unref(priv->modem_manager);
        g_clear_object(&priv->modem_manager);
    }

    modem_cleanup(self);

    G_OBJECT_CLASS(nm_device_bt_parent_class)->dispose(object);

    g_clear_object(&priv->bz_mgr);
}