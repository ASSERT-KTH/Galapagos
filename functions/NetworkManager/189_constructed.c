constructed(GObject *object)
{
    NMAgentManagerPrivate *priv = NM_AGENT_MANAGER_GET_PRIVATE(object);

    G_OBJECT_CLASS(nm_agent_manager_parent_class)->constructed(object);

    priv->auth_mgr        = g_object_ref(nm_auth_manager_get());
    priv->session_monitor = g_object_ref(nm_session_monitor_get());

    nm_dbus_object_export(NM_DBUS_OBJECT(object));

    g_signal_connect(priv->auth_mgr,
                     NM_AUTH_MANAGER_SIGNAL_CHANGED,
                     G_CALLBACK(authority_changed_cb),
                     object);
}