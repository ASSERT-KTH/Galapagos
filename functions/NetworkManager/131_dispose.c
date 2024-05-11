dispose(GObject *object)
{
    NMDBusManager        *self = NM_DBUS_MANAGER(object);
    NMDBusManagerPrivate *priv = NM_DBUS_MANAGER_GET_PRIVATE(self);
    PrivateServer        *s, *s_safe;
    CallerInfo           *caller_info;

    /* All exported NMDBusObject instances keep the manager alive, so we don't
     * expect any remaining objects. */
    nm_assert(!priv->objects_by_path || g_hash_table_size(priv->objects_by_path) == 0);
    nm_assert(c_list_is_empty(&priv->objects_lst_head));

    nm_clear_pointer(&priv->objects_by_path, g_hash_table_destroy);

    c_list_for_each_entry_safe (s, s_safe, &priv->private_servers_lst_head, private_servers_lst)
        private_server_free(s);

    if (priv->objmgr_registration_id) {
        g_dbus_connection_unregister_object(priv->main_dbus_connection,
                                            nm_steal_int(&priv->objmgr_registration_id));
    }

    g_clear_object(&priv->main_dbus_connection);

    G_OBJECT_CLASS(nm_dbus_manager_parent_class)->dispose(object);

    while ((caller_info =
                c_list_first_entry(&priv->caller_info_lst_head, CallerInfo, caller_info_lst)))
        _caller_info_free(caller_info);
}