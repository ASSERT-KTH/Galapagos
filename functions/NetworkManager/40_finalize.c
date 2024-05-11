finalize(GObject *object)
{
    NMDeviceIPTunnelPrivate *priv = NM_DEVICE_IP_TUNNEL_GET_PRIVATE(object);

    g_free(priv->local);
    g_free(priv->remote);
    g_free(priv->input_key);
    g_free(priv->output_key);

    G_OBJECT_CLASS(nm_device_ip_tunnel_parent_class)->finalize(object);
}