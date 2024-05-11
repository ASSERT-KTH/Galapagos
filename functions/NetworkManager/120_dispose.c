dispose(GObject *object)
{
    NMDnsDnsmasq        *self = NM_DNS_DNSMASQ(object);
    NMDnsDnsmasqPrivate *priv = NM_DNS_DNSMASQ_GET_PRIVATE(self);

    priv->is_stopped = TRUE;

    nm_clear_g_source_inst(&priv->burst_retry_timeout_source);

    _main_cleanup(self, FALSE);

    nm_clear_pointer(&priv->set_server_ex_args, g_variant_unref);

    G_OBJECT_CLASS(nm_dns_dnsmasq_parent_class)->dispose(object);

    g_clear_object(&priv->dbus_connection);
}