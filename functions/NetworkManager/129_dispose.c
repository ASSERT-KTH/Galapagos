dispose(GObject *object)
{
    NMCheckpoint        *self = NM_CHECKPOINT(object);
    NMCheckpointPrivate *priv = NM_CHECKPOINT_GET_PRIVATE(self);

    nm_assert(c_list_is_empty(&self->checkpoints_lst));

    nm_clear_pointer(&priv->devices, g_hash_table_unref);
    nm_clear_pointer(&priv->connection_uuids, g_hash_table_unref);
    nm_clear_pointer(&priv->removed_devices, g_ptr_array_unref);
    nm_global_dns_config_free(priv->global_dns_config);

    nm_clear_g_signal_handler(priv->manager, &priv->dev_removed_id);
    g_clear_object(&priv->manager);

    nm_clear_g_source(&priv->timeout_id);

    G_OBJECT_CLASS(nm_checkpoint_parent_class)->dispose(object);
}