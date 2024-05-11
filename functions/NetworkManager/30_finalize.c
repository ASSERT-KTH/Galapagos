finalize(GObject *object)
{
    NMPPPManagerPrivate *priv = NM_PPP_MANAGER_GET_PRIVATE(object);

    g_free(priv->parent_iface);

    G_OBJECT_CLASS(nm_ppp_manager_parent_class)->finalize(object);
}