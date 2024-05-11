finalize(GObject *object)
{
    NMSettingTeamPortPrivate *priv = NM_SETTING_TEAM_PORT_GET_PRIVATE(object);

    nm_team_setting_free(priv->team_setting);

    G_OBJECT_CLASS(nm_setting_team_port_parent_class)->finalize(object);
}