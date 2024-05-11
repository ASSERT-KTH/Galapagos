finalize(GObject *object)
{
    NMVpnConnection        *self = NM_VPN_CONNECTION(object);
    NMVpnConnectionPrivate *priv = NM_VPN_CONNECTION_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_vpn_connection_parent_class)->finalize(object);

    g_free(priv->banner);
    g_free(priv->username);
    g_free(priv->dbus.bus_name);

    _l3cfg_l3cd_clear_all(self);
    _l3cfg_clear(self, priv->l3cfg_if);
    _l3cfg_clear(self, priv->l3cfg_dev);

    g_clear_object(&priv->plugin_info);
    g_clear_object(&priv->l3cfg_if);
    g_clear_object(&priv->l3cfg_dev);
    g_clear_object(&priv->netns);
    g_clear_object(&priv->dbus.connection);
}