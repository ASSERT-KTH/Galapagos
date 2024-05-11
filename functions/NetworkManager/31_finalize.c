finalize(GObject *object)
{
    NMSecretAgent        *self = NM_SECRET_AGENT(object);
    NMSecretAgentPrivate *priv = NM_SECRET_AGENT_GET_PRIVATE(self);

    g_free(priv->description);
    g_free(priv->identifier);
    g_free(priv->owner_username);
    g_free(priv->dbus_owner);

    nm_c_list_elem_free_all(&priv->permissions, g_free);

    g_clear_object(&priv->subject);

    g_clear_object(&priv->dbus_connection);

    G_OBJECT_CLASS(nm_secret_agent_parent_class)->finalize(object);

    _LOGT("finalized");
}