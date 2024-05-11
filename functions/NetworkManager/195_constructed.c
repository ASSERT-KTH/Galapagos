constructed(GObject *object)
{
    NMHttpClient        *self = NM_HTTP_CLIENT(object);
    NMHttpClientPrivate *priv = NM_HTTP_CLIENT_GET_PRIVATE(self);

    priv->context = g_main_context_ref_thread_default();

    priv->mhandle = curl_multi_init();
    if (!priv->mhandle)
        _LOGE("curl: failed to create multi-handle");
    else {
        curl_multi_setopt(priv->mhandle, CURLMOPT_SOCKETFUNCTION, _mhandle_socketfunction_cb);
        curl_multi_setopt(priv->mhandle, CURLMOPT_SOCKETDATA, self);
        curl_multi_setopt(priv->mhandle, CURLMOPT_TIMERFUNCTION, _mhandle_timerfunction_cb);
        curl_multi_setopt(priv->mhandle, CURLMOPT_TIMERDATA, self);
    }

    G_OBJECT_CLASS(nm_http_client_parent_class)->constructed(object);
}