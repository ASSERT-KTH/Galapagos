dispose(GObject *object)
{
    NMPNetns        *self = NMP_NETNS(object);
    NMPNetnsPrivate *priv = NMP_NETNS_GET_PRIVATE(self);

    nm_close(priv->fd_net);
    priv->fd_net = -1;

    nm_close(priv->fd_mnt);
    priv->fd_mnt = -1;

    G_OBJECT_CLASS(nmp_netns_parent_class)->dispose(object);
}