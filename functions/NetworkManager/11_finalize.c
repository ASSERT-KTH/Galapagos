finalize(GObject *object)
{
    NMDeviceWireGuard        *self = NM_DEVICE_WIREGUARD(object);
    NMDeviceWireGuardPrivate *priv = NM_DEVICE_WIREGUARD_GET_PRIVATE(self);

    nm_explicit_bzero(priv->lnk_curr.private_key, sizeof(priv->lnk_curr.private_key));

    if (priv->dns_manager) {
        g_signal_handlers_disconnect_by_func(priv->dns_manager, _dns_config_changed, self);
        g_object_unref(priv->dns_manager);
    }

    g_hash_table_destroy(priv->peers);

    G_OBJECT_CLASS(nm_device_wireguard_parent_class)->finalize(object);
}