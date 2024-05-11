finalize(GObject *object)
{
    NMVpnConnectionPrivate *priv = NM_VPN_CONNECTION_GET_PRIVATE(object);

    g_free(priv->banner);

    G_OBJECT_CLASS(nm_vpn_connection_parent_class)->finalize(object);
}