dispose(GObject *object)
{
    NMModemManager        *self = NM_MODEM_MANAGER(object);
    NMModemManagerPrivate *priv = NM_MODEM_MANAGER_GET_PRIVATE(self);

    nm_clear_g_cancellable(&priv->main_cancellable);
    nm_clear_g_cancellable(&priv->modm.poke_cancellable);

    nm_clear_g_source(&priv->modm.relaunch_id);

    nm_clear_g_cancellable(&priv->modm.proxy_cancellable);
    g_clear_object(&priv->modm.proxy);
    nm_clear_g_free(&priv->modm.proxy_name_owner);

    modm_clear_manager(self);

#if WITH_OFONO
    if (priv->ofono.proxy) {
        g_signal_handlers_disconnect_by_func(priv->ofono.proxy, ofono_name_owner_changed, self);
        g_signal_handlers_disconnect_by_func(priv->ofono.proxy, ofono_signal_cb, self);
        g_clear_object(&priv->ofono.proxy);
    }
    nm_clear_g_cancellable(&priv->ofono.cancellable);
#endif

    g_clear_object(&priv->dbus_connection);

    if (priv->modems) {
        g_hash_table_foreach_remove(priv->modems, remove_one_modem, object);
        g_hash_table_destroy(priv->modems);
        priv->modems = NULL;
    }

    G_OBJECT_CLASS(nm_modem_manager_parent_class)->dispose(object);
}