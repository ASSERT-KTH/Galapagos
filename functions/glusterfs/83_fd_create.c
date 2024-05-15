fd_create (inode_t *inode, pid_t pid)
{
        fd_t *fd = NULL;

        fd = __fd_create (inode, (uint64_t)pid);
        if (!fd)
                goto out;

        fd = fd_ref (fd);

out:
        return fd;
}