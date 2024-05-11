_nm_connection_new_setting(NMConnection *connection, GType gtype)
{
    NMSetting *setting;

    nm_assert(g_type_is_a(gtype, NM_TYPE_SETTING));

    setting = g_object_new(gtype, NULL);
    nm_connection_add_setting(connection, setting);
    return setting;
}