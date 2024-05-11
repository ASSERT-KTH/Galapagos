constructed(GObject *object)
{
    NMModemPrivate *priv;

    G_OBJECT_CLASS(nm_modem_parent_class)->constructed(object);

    priv = NM_MODEM_GET_PRIVATE(NM_MODEM(object));

    g_return_if_fail(priv->control_port);
}