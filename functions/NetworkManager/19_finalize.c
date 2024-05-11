finalize(GObject *object)
{
    NMDnsMasqManagerPrivate *priv = NM_DNSMASQ_MANAGER_GET_PRIVATE(object);

    nm_dnsmasq_manager_stop(NM_DNSMASQ_MANAGER(object));

    g_free(priv->iface);
    g_free(priv->pidfile);

    G_OBJECT_CLASS(nm_dnsmasq_manager_parent_class)->finalize(object);
}