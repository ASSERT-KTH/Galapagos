finalize(GObject *object)
{
    NMSettingSriov *self = NM_SETTING_SRIOV(object);

    g_ptr_array_unref(self->vfs);

    G_OBJECT_CLASS(nm_setting_sriov_parent_class)->finalize(object);
}