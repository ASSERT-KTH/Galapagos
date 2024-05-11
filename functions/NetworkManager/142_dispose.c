dispose(GObject *object)
{
    NMSecretAgent        *self = NM_SECRET_AGENT(object);
    NMSecretAgentPrivate *priv = NM_SECRET_AGENT_GET_PRIVATE(self);

    nm_assert(c_list_is_empty(&self->agent_lst));
    nm_assert(!self->auth_chain);
    nm_assert(c_list_is_empty(&priv->requests));

    nm_clear_g_dbus_connection_signal(priv->dbus_connection, &priv->name_owner_changed_id);

    nm_clear_g_cancellable(&priv->name_owner_cancellable);

    G_OBJECT_CLASS(nm_secret_agent_parent_class)->dispose(object);
}