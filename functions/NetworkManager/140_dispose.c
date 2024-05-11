dispose(GObject *object)
{
    NMPPPManager        *self = (NMPPPManager *) object;
    NMPPPManagerPrivate *priv = NM_PPP_MANAGER_GET_PRIVATE(self);

    /* we expect the user to first stop the manager. As fallback,
     * still stop. */
    g_warn_if_fail(!priv->pid);
    g_warn_if_fail(!nm_dbus_object_is_exported(NM_DBUS_OBJECT(self)));
    _ppp_manager_stop(self, NULL, NULL, NULL);

    g_clear_object(&priv->act_req);

    G_OBJECT_CLASS(nm_ppp_manager_parent_class)->dispose(object);
}