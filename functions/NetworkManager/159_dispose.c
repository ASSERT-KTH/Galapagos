dispose(GObject *object)
{
    NMSecretAgentSimplePrivate *priv  = NM_SECRET_AGENT_SIMPLE_GET_PRIVATE(object);
    gs_free_error GError       *error = NULL;
    GHashTableIter              iter;
    RequestData                *request;

    g_hash_table_iter_init(&iter, priv->requests);
    while (g_hash_table_iter_next(&iter, NULL, (gpointer *) &request)) {
        if (!error)
            nm_utils_error_set_cancelled(&error, TRUE, "NMSecretAgentSimple");
        _request_data_complete(request, NULL, error, &iter);
    }

    G_OBJECT_CLASS(nm_secret_agent_simple_parent_class)->dispose(object);
}