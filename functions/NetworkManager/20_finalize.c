finalize(GObject *object)
{
    NMNDisc             *ndisc = NM_NDISC(object);
    NMNDiscPrivate      *priv  = NM_NDISC_GET_PRIVATE(ndisc);
    NMNDiscDataInternal *rdata = &priv->rdata;

    g_array_unref(rdata->gateways);
    g_array_unref(rdata->addresses);
    g_array_unref(rdata->routes);
    g_array_unref(rdata->dns_servers);
    g_array_unref(rdata->dns_domains);

    g_clear_object(&priv->netns);

    _config_clear(&priv->config_);

    nm_clear_l3cd(&priv->l3cd);

    G_OBJECT_CLASS(nm_ndisc_parent_class)->finalize(object);
}