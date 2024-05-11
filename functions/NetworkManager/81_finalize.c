finalize(GObject *object)
{
    NMSecretAgentSimplePrivate *priv = NM_SECRET_AGENT_SIMPLE_GET_PRIVATE(object);

    g_hash_table_destroy(priv->requests);

    g_free(priv->path);

    G_OBJECT_CLASS(nm_secret_agent_simple_parent_class)->finalize(object);
}