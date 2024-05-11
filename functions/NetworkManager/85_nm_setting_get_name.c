nm_setting_get_name(NMSetting *setting)
{
    const NMMetaSettingInfo *setting_info;

    g_return_val_if_fail(NM_IS_SETTING(setting), NULL);

    setting_info = NM_SETTING_GET_CLASS(setting)->setting_info;
    return setting_info ? setting_info->setting_name : NULL;
}