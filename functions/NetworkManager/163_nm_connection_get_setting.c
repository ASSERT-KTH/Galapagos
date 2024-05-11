nm_connection_get_setting(NMConnection *connection, GType setting_type)
{
    NMSetting               *setting;
    const NMMetaSettingInfo *setting_info;

    g_return_val_if_fail(NM_IS_CONNECTION(connection), NULL);

    setting_info = _nm_meta_setting_info_from_gtype(setting_type);

    if (!setting_info)
        g_return_val_if_reached(NULL);

    setting = NM_CONNECTION_GET_PRIVATE(connection)->settings[setting_info->meta_type];

    nm_assert(!setting || G_TYPE_CHECK_INSTANCE_TYPE(setting, setting_type));

    return setting;
}