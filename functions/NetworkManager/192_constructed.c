constructed(GObject *object)
{
    NMClient        *self = NM_CLIENT(object);
    NMClientPrivate *priv = NM_CLIENT_GET_PRIVATE(self);

    priv->main_context = g_main_context_ref_thread_default();

    G_OBJECT_CLASS(nm_client_parent_class)->constructed(object);

    NML_NMCLIENT_LOG_D(self, "new NMClient instance");
}