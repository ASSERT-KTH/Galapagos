dispose(GObject *object)
{
    NMSecretAgentOld *self = NM_SECRET_AGENT_OLD(object);

    _LOGT("disposing");

    _secret_agent_old_destroy(self);

    G_OBJECT_CLASS(nm_secret_agent_old_parent_class)->dispose(object);
}