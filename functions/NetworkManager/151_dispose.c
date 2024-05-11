dispose(GObject *object)
{
    NMRemoteConnectionPrivate *priv = NM_REMOTE_CONNECTION_GET_PRIVATE(object);

    nm_clear_g_free(&priv->filename);

    G_OBJECT_CLASS(nm_remote_connection_parent_class)->dispose(object);
}