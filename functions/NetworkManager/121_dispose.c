dispose(GObject *object)
{
    NMDnsSystemdResolved        *self = NM_DNS_SYSTEMD_RESOLVED(object);
    NMDnsSystemdResolvedPrivate *priv = NM_DNS_SYSTEMD_RESOLVED_GET_PRIVATE(self);

    stop(NM_DNS_PLUGIN(self));

    g_clear_object(&priv->dbus_connection);
    nm_clear_pointer(&priv->dirty_interfaces, g_hash_table_destroy);

    G_OBJECT_CLASS(nm_dns_systemd_resolved_parent_class)->dispose(object);
}