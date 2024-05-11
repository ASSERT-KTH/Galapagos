finalize(GObject *object)
{
    NMPolicy        *self = NM_POLICY(object);
    NMPolicyPrivate *priv = NM_POLICY_GET_PRIVATE(self);

    g_hash_table_unref(priv->devices);

    G_OBJECT_CLASS(nm_policy_parent_class)->finalize(object);

    g_object_unref(priv->netns);
}