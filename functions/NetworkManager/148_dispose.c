dispose(GObject *object)
{
    NMSupplicantManager        *self = (NMSupplicantManager *) object;
    NMSupplicantManagerPrivate *priv = NM_SUPPLICANT_MANAGER_GET_PRIVATE(self);

    _supp_iface_remove_all(self, TRUE, "NMSupplicantManager is disposing");

    nm_assert(c_list_is_empty(&priv->create_iface_lst_head));

    nm_clear_g_source(&priv->available_reset_id);

    priv->available = NM_TERNARY_FALSE;
    nm_clear_pointer(&priv->name_owner, nm_ref_string_unref);

    nm_clear_g_source(&priv->poke_name_owner_timeout_id);
    nm_clear_g_cancellable(&priv->poke_name_owner_cancellable);

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->interface_removed_id);
    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->name_owner_changed_id);

    nm_clear_g_cancellable(&priv->get_name_owner_cancellable);
    nm_clear_g_cancellable(&priv->get_capabilities_cancellable);

    G_OBJECT_CLASS(nm_supplicant_manager_parent_class)->dispose(object);

    g_clear_object(&priv->dbus_connection);

    nm_clear_pointer(&priv->supp_ifaces, g_hash_table_destroy);
}