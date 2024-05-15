fd_unref (fd_t *fd)
{
        int32_t refcount = 0;

        if (!fd) {
                gf_log_callingfn ("fd", GF_LOG_ERROR, "fd is NULL");
                return;
        }

        LOCK (&fd->inode->lock);
        {
                __fd_unref (fd);
                refcount = fd->refcount;
        }
        UNLOCK (&fd->inode->lock);

        if (refcount == 0) {
                fd_destroy (fd);
        }

        return ;
}