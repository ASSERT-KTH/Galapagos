finalize(GObject *object)
{
    NMModemPrivate *priv = NM_MODEM_GET_PRIVATE(object);

    g_free(priv->uid);
    g_free(priv->path);
    g_free(priv->driver);
    g_free(priv->control_port);
    g_free(priv->data_port);
    g_free(priv->device_id);
    g_free(priv->sim_id);
    g_free(priv->sim_operator_id);
    g_free(priv->operator_code);
    g_free(priv->apn);

    G_OBJECT_CLASS(nm_modem_parent_class)->finalize(object);
}