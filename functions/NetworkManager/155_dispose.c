dispose(GObject *object)
{
    NMVpnPluginInfo        *self = NM_VPN_PLUGIN_INFO(object);
    NMVpnPluginInfoPrivate *priv = NM_VPN_PLUGIN_INFO_GET_PRIVATE(self);

    g_clear_object(&priv->editor_plugin);

    G_OBJECT_CLASS(nm_vpn_plugin_info_parent_class)->dispose(object);
}