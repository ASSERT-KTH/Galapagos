nfs3_cbk_errno_status (int32_t op_ret, int32_t op_errno)
{
        if ((op_ret == -1) && (op_errno == 0)) {
                return NFS3ERR_SERVERFAULT;
        }

        return nfs3_errno_to_nfsstat3 (op_errno);
}