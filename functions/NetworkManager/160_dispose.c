dispose(GObject *object)
{
    NMHttpClient        *self = NM_HTTP_CLIENT(object);
    NMHttpClientPrivate *priv = NM_HTTP_CLIENT_GET_PRIVATE(self);

    nm_clear_pointer(&priv->mhandle, curl_multi_cleanup);
    nm_clear_pointer(&priv->source_sockets_hashtable, g_hash_table_unref);

    nm_clear_g_source_inst(&priv->mhandle_source_timeout);

    G_OBJECT_CLASS(nm_http_client_parent_class)->dispose(object);
}