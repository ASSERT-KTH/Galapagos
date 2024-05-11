dispose(GObject *object)
{
    NMModemBroadband        *self = NM_MODEM_BROADBAND(object);
    NMModemBroadbandPrivate *priv = NM_MODEM_BROADBAND_GET_PRIVATE(self);

    connect_context_clear(self);
    g_clear_object(&priv->ipv4_config);
    g_clear_object(&priv->ipv6_config);
    g_clear_object(&priv->bearer);

    if (priv->modem_iface) {
        g_signal_handlers_disconnect_by_data(priv->modem_iface, self);
        g_clear_object(&priv->modem_iface);
    }

    if (priv->modem_3gpp_iface) {
        g_signal_handlers_disconnect_by_data(priv->modem_3gpp_iface, self);
        g_clear_object(&priv->modem_3gpp_iface);
    }

    g_clear_object(&priv->simple_iface);
    g_clear_object(&priv->sim_iface);
    g_clear_object(&priv->modem_object);

    G_OBJECT_CLASS(nm_modem_broadband_parent_class)->dispose(object);
}