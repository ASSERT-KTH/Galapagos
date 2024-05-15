nfs3_call_state_wipe (nfs3_call_state_t *cs)
{
        if (!cs)
                return;

        if (cs->fd) {
                gf_log (GF_NFS3, GF_LOG_TRACE, "fd 0x%lx ref: %d",
                        (long)cs->fd, cs->fd->refcount);
                fd_unref (cs->fd);
        }

        GF_FREE (cs->resolventry);

        GF_FREE (cs->pathname);

        if (!list_empty (&cs->entries.list))
                gf_dirent_free (&cs->entries);

        nfs_loc_wipe (&cs->oploc);
        nfs_loc_wipe (&cs->resolvedloc);
        if (cs->iob)
                iobuf_unref (cs->iob);
        if (cs->iobref)
                iobref_unref (cs->iobref);
        if (cs->trans)
                rpc_transport_unref (cs->trans);
        memset (cs, 0, sizeof (*cs));
        mem_put (cs);
        /* Already refd by fd_lookup, so no need to ref again. */
}