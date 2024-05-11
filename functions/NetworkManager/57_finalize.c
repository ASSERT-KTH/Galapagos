finalize(GObject *object)
{
    NMSetting8021x        *self = NM_SETTING_802_1X(object);
    NMSetting8021xPrivate *priv = NM_SETTING_802_1X_GET_PRIVATE(self);

    g_slist_free_full(priv->eap, g_free);
    g_slist_free_full(priv->altsubject_matches, g_free);
    g_slist_free_full(priv->phase2_altsubject_matches, g_free);

    G_OBJECT_CLASS(nm_setting_802_1x_parent_class)->finalize(object);
}