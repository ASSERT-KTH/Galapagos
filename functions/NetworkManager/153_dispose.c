dispose(GObject *object)
{
    NMVpnPluginOld        *plugin = NM_VPN_PLUGIN_OLD(object);
    NMVpnPluginOldPrivate *priv   = NM_VPN_PLUGIN_OLD_GET_PRIVATE(plugin);
    NMVpnServiceState      state;
    GError                *err = NULL;

    nm_clear_g_source(&priv->fail_stop_id);
    nm_clear_g_source(&priv->quit_timer);
    nm_clear_g_source(&priv->connect_timer);

    state = nm_vpn_plugin_old_get_state(plugin);

    if (state == NM_VPN_SERVICE_STATE_STARTED || state == NM_VPN_SERVICE_STATE_STARTING)
        nm_vpn_plugin_old_disconnect(plugin, &err);

    if (err) {
        g_warning("Error disconnecting VPN connection: %s", err->message);
        g_error_free(err);
    }

    G_OBJECT_CLASS(nm_vpn_plugin_old_parent_class)->dispose(object);
}