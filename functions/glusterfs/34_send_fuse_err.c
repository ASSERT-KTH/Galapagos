send_fuse_err (xlator_t *this, fuse_in_header_t *finh, int error)
{
        struct fuse_out_header fouh = {0, };
        struct iovec iov_out;
        inode_t  *inode = NULL;

        fouh.error = -error;
        iov_out.iov_base = &fouh;

        inode = fuse_ino_to_inode (finh->nodeid, this);

        // filter out ENOENT
        if (error != ENOENT) {
                if (inode) {
                        fuse_log_eh (this,"Sending %s for operation %d on "
                                     "inode %s", strerror (error), finh->opcode,
                                     uuid_utoa (inode->gfid));
                } else {
                        fuse_log_eh (this, "Sending %s for operation %d on "
                                     "inode %" GF_PRI_INODE,  strerror (error),
                                     finh->opcode, finh->nodeid);
                }
        }

        if (inode)
                inode_unref (inode);

        return send_fuse_iov (this, finh, &iov_out, 1);
}