dispose(GObject *object)
{
    NMCSProvider        *self = NMCS_PROVIDER(object);
    NMCSProviderPrivate *priv = NMCS_PROVIDER_GET_PRIVATE(self);

    g_clear_object(&priv->http_client);

    G_OBJECT_CLASS(nmcs_provider_parent_class)->dispose(object);
}