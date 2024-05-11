finalize(GObject *object)
{
    NMManagerPrivate *priv = NM_MANAGER_GET_PRIVATE(object);

    g_array_free(priv->capabilities, TRUE);

    G_OBJECT_CLASS(nm_manager_parent_class)->finalize(object);

    g_object_unref(priv->platform);
}