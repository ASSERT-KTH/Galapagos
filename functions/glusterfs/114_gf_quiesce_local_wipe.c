gf_quiesce_local_wipe (xlator_t *this, quiesce_local_t *local)
{
        if (!local || !this || !this->private)
                return;

        if (local->loc.inode)
                loc_wipe (&local->loc);
        if (local->fd)
                fd_unref (local->fd);
        GF_FREE (local->name);
        GF_FREE (local->volname);
        if (local->dict)
                dict_unref (local->dict);
        if (local->iobref)
                iobref_unref (local->iobref);
        GF_FREE (local->vector);

        mem_put (local);
}