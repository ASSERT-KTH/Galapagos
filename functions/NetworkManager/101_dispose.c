dispose(GObject *object)
{
    NMDeviceTeam        *self = NM_DEVICE_TEAM(object);
    NMDeviceTeamPrivate *priv = NM_DEVICE_TEAM_GET_PRIVATE(self);

    if (priv->teamd_dbus_watch) {
        g_bus_unwatch_name(priv->teamd_dbus_watch);
        priv->teamd_dbus_watch = 0;
    }

    if (priv->usock_monitor) {
        g_signal_handlers_disconnect_by_data(priv->usock_monitor, object);
        g_clear_object(&priv->usock_monitor);
    }

    teamd_cleanup(self, TRUE);
    nm_clear_g_free(&priv->config);
    nm_clear_pointer(&priv->port_configs, g_hash_table_destroy);

    G_OBJECT_CLASS(nm_device_team_parent_class)->dispose(object);
}