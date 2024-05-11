finalize(GObject *object)
{
    NMHttpClient        *self = NM_HTTP_CLIENT(object);
    NMHttpClientPrivate *priv = NM_HTTP_CLIENT_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_http_client_parent_class)->finalize(object);

    g_main_context_unref(priv->context);

    curl_global_cleanup();
}