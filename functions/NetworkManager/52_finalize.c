finalize(GObject *object)
{
    NMSecretAgentOld        *self = NM_SECRET_AGENT_OLD(object);
    NMSecretAgentOldPrivate *priv = NM_SECRET_AGENT_OLD_GET_PRIVATE(self);

    _LOGT("finalizing");

    if (priv->dbus_context) {
        nml_cleanup_context_busy_watcher_on_idle(g_steal_pointer(&priv->context_busy_watcher),
                                                 priv->dbus_context);
    }

    g_clear_object(&priv->dbus_connection);
    nm_clear_pointer(&priv->dbus_context, g_main_context_unref);
    nm_clear_pointer(&priv->main_context, g_main_context_unref);

    g_clear_object(&priv->context_busy_watcher);

    g_free(priv->identifier);

    G_OBJECT_CLASS(nm_secret_agent_old_parent_class)->finalize(object);
}