finalize(GObject *object)
{
    NMActiveConnectionPrivate *priv = NM_ACTIVE_CONNECTION_GET_PRIVATE(object);

    g_free(priv->id);
    g_free(priv->uuid);
    g_free(priv->type);
    nm_ref_string_unref(priv->specific_object_path);

    G_OBJECT_CLASS(nm_active_connection_parent_class)->finalize(object);
}