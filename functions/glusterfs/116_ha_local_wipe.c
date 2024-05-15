ha_local_wipe (ha_local_t *local)
{
        if (local->stub) {
                call_stub_destroy (local->stub);
                local->stub = NULL;
        }

        if (local->state) {
                GF_FREE (local->state);
                local->state = NULL;
        }

        if (local->dict) {
                dict_unref (local->dict);
                local->dict = NULL;
        }

        loc_wipe (&local->loc);

        if (local->fd) {
                fd_unref (local->fd);
                local->fd = NULL;
        }

        if (local->inode) {
                inode_unref (local->inode);
                local->inode = NULL;
        }

        GF_FREE (local);
        return;
}