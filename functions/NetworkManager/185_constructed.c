constructed(GObject *object)
{
    NMActiveConnection        *self = (NMActiveConnection *) object;
    NMActiveConnectionPrivate *priv = NM_ACTIVE_CONNECTION_GET_PRIVATE(self);

    G_OBJECT_CLASS(nm_active_connection_parent_class)->constructed(object);

    if (!priv->applied_connection && priv->settings_connection.obj)
        priv->applied_connection = nm_simple_connection_new_clone(
            nm_settings_connection_get_connection(priv->settings_connection.obj));

    _LOGD("constructed (%s, version-id %llu, type %s)",
          G_OBJECT_TYPE_NAME(self),
          (unsigned long long) priv->version_id,
          nm_activation_type_to_string(priv->activation_type));

    if (priv->applied_connection) {
        /* priv->applied_connection was set during the construction of the object.
         * It's not yet fully initialized, so do that now.
         *
         * We delayed that, because we may log in _set_applied_connection_take(), and the
         * first logging line should be "constructed" above). */
        _set_applied_connection_take(self, g_steal_pointer(&priv->applied_connection));
    }

    if (NM_FLAGS_HAS(priv->state_flags,
                     NM_ACTIVATION_STATE_FLAG_LIFETIME_BOUND_TO_PROFILE_VISIBILITY))
        nm_keep_alive_set_settings_connection_watch_visible(priv->keep_alive,
                                                            priv->settings_connection.obj);

    g_return_if_fail(priv->subject);
    g_return_if_fail(priv->activation_reason != NM_ACTIVATION_REASON_UNSET);
}