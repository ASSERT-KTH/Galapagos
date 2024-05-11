constructed(GObject *object)
{
    NMDevice              *device  = NM_DEVICE(object);
    NMDeviceTeamPrivate   *priv    = NM_DEVICE_TEAM_GET_PRIVATE(device);
    gs_free char          *tmp_str = NULL;
    gs_unref_object GFile *file    = NULL;
    gs_free_error GError  *error   = NULL;

    G_OBJECT_CLASS(nm_device_team_parent_class)->constructed(object);

    priv->port_configs = g_hash_table_new_full(nm_str_hash, g_str_equal, g_free, g_free);

    if (nm_dbus_manager_get_dbus_connection(nm_dbus_manager_get())) {
        /* Register D-Bus name watcher */
        tmp_str = g_strdup_printf("org.libteam.teamd.%s", nm_device_get_ip_iface(device));
        priv->teamd_dbus_watch = g_bus_watch_name(G_BUS_TYPE_SYSTEM,
                                                  tmp_str,
                                                  G_BUS_NAME_WATCHER_FLAGS_NONE,
                                                  teamd_dbus_appeared,
                                                  teamd_dbus_vanished,
                                                  NM_DEVICE(device),
                                                  NULL);
        return;
    }

    /* No D-Bus, watch unix socket */
    tmp_str             = g_strdup_printf("/run/teamd/%s.sock", nm_device_get_ip_iface(device));
    file                = g_file_new_for_path(tmp_str);
    priv->usock_monitor = g_file_monitor_file(file, G_FILE_MONITOR_NONE, NULL, &error);
    if (!priv->usock_monitor) {
        nm_log_warn(LOGD_TEAM, "error monitoring %s: %s", tmp_str, error->message);
    } else {
        g_signal_connect(priv->usock_monitor, "changed", G_CALLBACK(monitor_changed_cb), object);
    }
}