finalize(GObject *object)
{
    NMDnsManager        *self = NM_DNS_MANAGER(object);
    NMDnsManagerPrivate *priv = NM_DNS_MANAGER_GET_PRIVATE(self);

    g_free(priv->hostdomain);
    g_free(priv->mode);

    G_OBJECT_CLASS(nm_dns_manager_parent_class)->finalize(object);
}