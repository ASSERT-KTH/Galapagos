fd_ref (fd_t *fd)
{
        fd_t *refed_fd = NULL;

        if (!fd) {
                gf_log_callingfn ("fd", GF_LOG_ERROR, "null fd");
                return NULL;
        }

        LOCK (&fd->inode->lock);
        refed_fd = __fd_ref (fd);
        UNLOCK (&fd->inode->lock);

        return refed_fd;
}