fop_log_level (glusterfs_fop_t fop, int op_errno)
{
        /* if gfid doesn't exist ESTALE comes */
        if (op_errno == ENOENT || op_errno == ESTALE)
                return GF_LOG_DEBUG;

        if ((fop == GF_FOP_ENTRYLK) ||
            (fop == GF_FOP_FENTRYLK) ||
            (fop == GF_FOP_FINODELK) ||
            (fop == GF_FOP_INODELK) ||
            (fop == GF_FOP_LK)) {
                /*
                 * if non-blocking lock fails EAGAIN comes
                 * if locks xlator is not loaded ENOSYS comes
                 */
                if (op_errno == EAGAIN || op_errno == ENOSYS)
                        return GF_LOG_DEBUG;
        }

        if ((fop == GF_FOP_GETXATTR) ||
            (fop == GF_FOP_FGETXATTR)) {
                if (op_errno == ENOTSUP || op_errno == ENODATA)
                        return GF_LOG_DEBUG;
        }

        if ((fop == GF_FOP_SETXATTR) ||
            (fop == GF_FOP_FSETXATTR) ||
            (fop == GF_FOP_REMOVEXATTR) ||
            (fop == GF_FOP_FREMOVEXATTR)) {
                if (op_errno == ENOTSUP)
                        return GF_LOG_DEBUG;
        }

        return GF_LOG_ERROR;
}