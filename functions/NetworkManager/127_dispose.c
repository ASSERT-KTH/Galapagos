dispose(GObject *object)
{
#if HAVE_LIBAUDIT
    NMAuditManager        *self = NM_AUDIT_MANAGER(object);
    NMAuditManagerPrivate *priv = NM_AUDIT_MANAGER_GET_PRIVATE(self);

    if (priv->config) {
        g_signal_handlers_disconnect_by_func(priv->config, config_changed_cb, self);
        g_clear_object(&priv->config);
    }

    if (priv->auditd_fd >= 0) {
        audit_close(priv->auditd_fd);
        priv->auditd_fd = -1;
    }
#endif

    G_OBJECT_CLASS(nm_audit_manager_parent_class)->dispose(object);
}