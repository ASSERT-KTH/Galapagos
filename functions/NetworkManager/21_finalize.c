finalize(GObject *object)
{
    NMActiveConnection        *self = NM_ACTIVE_CONNECTION(object);
    NMActiveConnectionPrivate *priv = NM_ACTIVE_CONNECTION_GET_PRIVATE(self);

    nm_dbus_track_obj_path_set(&priv->settings_connection, NULL, FALSE);

    nm_clear_pointer(&priv->keep_alive, nm_keep_alive_destroy);

    G_OBJECT_CLASS(nm_active_connection_parent_class)->finalize(object);
}