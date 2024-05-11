dispose(GObject *object)
{
    NMVpnManagerPrivate *priv = NM_VPN_MANAGER_GET_PRIVATE(object);

    if (priv->monitor_etc) {
        if (priv->monitor_id_etc)
            g_signal_handler_disconnect(priv->monitor_etc, priv->monitor_id_etc);
        g_file_monitor_cancel(priv->monitor_etc);
        g_clear_object(&priv->monitor_etc);
    }

    if (priv->monitor_lib) {
        if (priv->monitor_id_lib)
            g_signal_handler_disconnect(priv->monitor_lib, priv->monitor_id_lib);
        g_file_monitor_cancel(priv->monitor_lib);
        g_clear_object(&priv->monitor_lib);
    }

    while (priv->plugins)
        nm_vpn_plugin_info_list_remove(&priv->plugins, priv->plugins->data);

    g_hash_table_unref(priv->active_services);

    G_OBJECT_CLASS(nm_vpn_manager_parent_class)->dispose(object);
}