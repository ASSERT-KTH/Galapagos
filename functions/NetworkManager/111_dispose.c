dispose(GObject *object)
{
    NMModemPrivate *priv = NM_MODEM_GET_PRIVATE(object);

    g_clear_object(&priv->act_req);
    g_clear_object(&priv->device);

    G_OBJECT_CLASS(nm_modem_parent_class)->dispose(object);
}