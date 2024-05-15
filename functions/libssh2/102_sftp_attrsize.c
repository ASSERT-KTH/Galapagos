static int sftp_attrsize(unsigned long flags)
{
    return 4 +                                 /* flags(4) */
           ((flags & LIBSSH2_SFTP_ATTR_SIZE) ? 8 : 0) +
           ((flags & LIBSSH2_SFTP_ATTR_UIDGID) ? 8 : 0) +
           ((flags & LIBSSH2_SFTP_ATTR_PERMISSIONS) ? 4 : 0) +
           ((flags & LIBSSH2_SFTP_ATTR_ACMODTIME) ? 8 : 0);
    /* atime + mtime as u32 */
}