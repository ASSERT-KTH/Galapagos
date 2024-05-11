constructed(GObject *object)
{
    NMDeviceIPTunnelPrivate *priv = NM_DEVICE_IP_TUNNEL_GET_PRIVATE(object);

    if (NM_IN_SET(priv->mode,
                  NM_IP_TUNNEL_MODE_IPIP6,
                  NM_IP_TUNNEL_MODE_IP6IP6,
                  NM_IP_TUNNEL_MODE_IP6GRE,
                  NM_IP_TUNNEL_MODE_IP6GRETAP,
                  NM_IP_TUNNEL_MODE_VTI6))
        priv->addr_family = AF_INET6;
    else
        priv->addr_family = AF_INET;

    G_OBJECT_CLASS(nm_device_ip_tunnel_parent_class)->constructed(object);
}