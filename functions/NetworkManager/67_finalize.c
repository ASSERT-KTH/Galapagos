finalize(GObject *object)
{
    NMSettingTCConfig *self = NM_SETTING_TC_CONFIG(object);

    g_ptr_array_unref(self->qdiscs);
    g_ptr_array_unref(self->tfilters);

    G_OBJECT_CLASS(nm_setting_tc_config_parent_class)->finalize(object);
}