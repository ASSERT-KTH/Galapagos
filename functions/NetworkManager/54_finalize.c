finalize(GObject *object)
{
    NMVpnPluginOld        *plugin = NM_VPN_PLUGIN_OLD(object);
    NMVpnPluginOldPrivate *priv   = NM_VPN_PLUGIN_OLD_GET_PRIVATE(plugin);

    nm_vpn_plugin_old_set_connection(plugin, NULL);
    g_free(priv->dbus_service_name);

    nm_clear_pointer(&priv->banner, g_variant_unref);
    nm_clear_pointer(&priv->tundev, g_variant_unref);
    nm_clear_pointer(&priv->gateway, g_variant_unref);
    nm_clear_pointer(&priv->mtu, g_variant_unref);

    G_OBJECT_CLASS(nm_vpn_plugin_old_parent_class)->finalize(object);
}