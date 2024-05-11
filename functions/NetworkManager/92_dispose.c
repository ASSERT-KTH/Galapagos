dispose(GObject *object)
{
    NMBluezManager        *self = NM_BLUEZ_MANAGER(object);
    NMBluezManagerPrivate *priv = NM_BLUEZ_MANAGER_GET_PRIVATE(self);

    /* FIXME(shutdown): we need a nm_device_factory_stop() hook to first unregister all
     *   BzDBusObj instances and do necessary cleanup actions (like disconnecting devices
     *   or deleting panu_connection). */

    nm_clear_g_source(&priv->process_change_idle_id);

    g_atomic_pointer_compare_and_exchange(&nm_bt_vtable_network_server,
                                          &priv->vtable_network_server,
                                          NULL);

    _cleanup_all(self);

    G_OBJECT_CLASS(nm_bluez_manager_parent_class)->dispose(object);

    g_clear_object(&priv->settings);
    g_clear_object(&priv->manager);
    g_clear_object(&priv->dbus_connection);

    nm_clear_pointer(&priv->bzobjs, g_hash_table_destroy);
    nm_clear_pointer(&priv->conn_data_heads, g_hash_table_destroy);
    nm_clear_pointer(&priv->conn_data_elems, g_hash_table_destroy);

    nm_assert(c_list_is_empty(&priv->network_server_lst_head));
    nm_assert(c_list_is_empty(&priv->process_change_lst_head));
}