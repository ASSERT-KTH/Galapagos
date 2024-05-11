constructed(GObject *object)
{
    NMDeviceBt        *self = NM_DEVICE_BT(object);
    NMDeviceBtPrivate *priv = NM_DEVICE_BT_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_device_bt_parent_class)->constructed(object);

    priv->modem_manager = g_object_ref(nm_modem_manager_get());

    nm_modem_manager_name_owner_ref(priv->modem_manager);

    g_signal_connect(priv->modem_manager,
                     NM_MODEM_MANAGER_MODEM_ADDED,
                     G_CALLBACK(mm_modem_added_cb),
                     self);

    g_signal_connect(priv->modem_manager,
                     "notify::" NM_MODEM_MANAGER_NAME_OWNER,
                     G_CALLBACK(mm_name_owner_changed_cb),
                     self);

    set_mm_running(self);
}