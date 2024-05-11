dispose(GObject *object)
{
    NMAgentManager        *self = NM_AGENT_MANAGER(object);
    NMAgentManagerPrivate *priv = NM_AGENT_MANAGER_GET_PRIVATE(self);
    Request               *request;
    NMSecretAgent         *agent;

    while ((request = c_list_first_entry(&priv->request_lst_head, Request, request_lst))) {
        c_list_unlink(&request->request_lst);
        req_complete_cancel(request, TRUE);
    }

    while ((agent = c_list_first_entry(&priv->agent_lst_head, NMSecretAgent, agent_lst)))
        _agent_remove(self, agent);

    if (priv->auth_mgr) {
        g_signal_handlers_disconnect_by_func(priv->auth_mgr,
                                             G_CALLBACK(authority_changed_cb),
                                             object);
        g_clear_object(&priv->auth_mgr);
    }

    nm_dbus_object_unexport(NM_DBUS_OBJECT(object));

    g_clear_object(&priv->session_monitor);

    G_OBJECT_CLASS(nm_agent_manager_parent_class)->dispose(object);
}