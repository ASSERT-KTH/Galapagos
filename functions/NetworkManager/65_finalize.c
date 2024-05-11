finalize(GObject *object)
{
    NMSettingOvsPort *self = NM_SETTING_OVS_PORT(object);

    g_ptr_array_unref(self->trunks);

    G_OBJECT_CLASS(nm_setting_ovs_port_parent_class)->finalize(object);
}