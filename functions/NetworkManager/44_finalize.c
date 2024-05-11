finalize(GObject *object)
{
    NMDeviceTeamPrivate *priv = NM_DEVICE_TEAM_GET_PRIVATE(object);

    g_free(priv->config);

    G_OBJECT_CLASS(nm_device_team_parent_class)->finalize(object);
}