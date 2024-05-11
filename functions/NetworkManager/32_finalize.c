finalize(GObject *object)
{
    NMSettingsStorage *self = NM_SETTINGS_STORAGE(object);

    c_list_unlink_stale(&self->_storage_lst);
    c_list_unlink_stale(&self->_storage_by_uuid_lst);

    g_object_unref(self->_plugin);
    g_free(self->_uuid);
    g_free(self->_filename);

    G_OBJECT_CLASS(nm_settings_storage_parent_class)->finalize(object);
}