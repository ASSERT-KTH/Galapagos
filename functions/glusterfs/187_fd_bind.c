fd_bind (fd_t *fd)
{
        if (!fd || !fd->inode) {
                gf_log_callingfn ("fd", GF_LOG_ERROR, "!fd || !fd->inode");
                return NULL;
        }

        LOCK (&fd->inode->lock);
        {
                fd = __fd_bind (fd);
        }
        UNLOCK (&fd->inode->lock);

        return fd;
}