dispose(GObject *object)
{
    NMDeviceIPTunnel        *self = NM_DEVICE_IP_TUNNEL(object);
    NMDeviceIPTunnelPrivate *priv = NM_DEVICE_IP_TUNNEL_GET_PRIVATE(self);

    nm_clear_g_free(&priv->local);
    nm_clear_g_free(&priv->remote);
    nm_clear_g_free(&priv->input_key);
    nm_clear_g_free(&priv->output_key);

    G_OBJECT_CLASS(nm_device_ip_tunnel_parent_class)->dispose(object);
}