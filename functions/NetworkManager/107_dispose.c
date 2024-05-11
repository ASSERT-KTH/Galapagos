dispose(GObject *object)
{
    NMIwdManager        *self = (NMIwdManager *) object;
    NMIwdManagerPrivate *priv = NM_IWD_MANAGER_GET_PRIVATE(self);

    release_object_manager(self);

    nm_clear_g_cancellable(&priv->cancellable);

    if (priv->settings) {
        g_signal_handlers_disconnect_by_data(priv->settings, self);
        g_clear_object(&priv->settings);
    }

    /* This may trigger mirror connection removals so it happens
     * after the g_signal_handlers_disconnect_by_data above.
     */
    nm_clear_pointer(&priv->known_networks, g_hash_table_destroy);

    if (priv->manager) {
        g_signal_handlers_disconnect_by_data(priv->manager, self);
        g_clear_object(&priv->manager);
    }

    priv->last_agent_call_device = NULL;

    nm_clear_g_free(&priv->last_state_dir);
    nm_clear_g_free(&priv->warned_state_dir);

    g_hash_table_unref(nm_steal_pointer(&priv->p2p_devices));

    g_slist_free_full(nm_steal_pointer(&priv->recently_mirrored), recently_mirrored_data_free);

    G_OBJECT_CLASS(nm_iwd_manager_parent_class)->dispose(object);
}