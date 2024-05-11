constructed(GObject *object)
{
    NMModemOfono        *self = NM_MODEM_OFONO(object);
    NMModemOfonoPrivate *priv = NM_MODEM_OFONO_GET_PRIVATE(self);

    g_dbus_proxy_new_for_bus(G_BUS_TYPE_SYSTEM,
                             G_DBUS_PROXY_FLAGS_DO_NOT_AUTO_START,
                             NULL,
                             OFONO_DBUS_SERVICE,
                             nm_modem_get_path(NM_MODEM(self)),
                             OFONO_DBUS_INTERFACE_MODEM,
                             priv->modem_proxy_cancellable,
                             modem_proxy_new_cb,
                             self);

    G_OBJECT_CLASS(nm_modem_ofono_parent_class)->constructed(object);
}