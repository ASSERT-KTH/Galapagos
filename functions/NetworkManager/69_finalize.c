finalize(GObject *object)
{
    NMSettingTeamPrivate *priv = NM_SETTING_TEAM_GET_PRIVATE(object);

    nm_team_setting_free(priv->team_setting);

    G_OBJECT_CLASS(nm_setting_team_parent_class)->finalize(object);
}