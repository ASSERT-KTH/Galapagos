dispose(GObject *object)
{
    NMHostnameManager        *self = NM_HOSTNAME_MANAGER(object);
    NMHostnameManagerPrivate *priv = NM_HOSTNAME_MANAGER_GET_PRIVATE(self);

    if (priv->hostnamed_proxy) {
        g_signal_handlers_disconnect_by_func(priv->hostnamed_proxy,
                                             G_CALLBACK(hostnamed_properties_changed),
                                             self);
        g_clear_object(&priv->hostnamed_proxy);
    }

    _file_monitors_clear(self);

    nm_clear_g_free(&priv->static_hostname);

    G_OBJECT_CLASS(nm_hostname_manager_parent_class)->dispose(object);
}