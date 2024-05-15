nfs3_log_common_res (uint32_t xid, int op, nfsstat3 stat, int pstat)
{
        char    errstr[1024];
        int     ll = nfs3_loglevel (op, stat);

        if (THIS->ctx->log.loglevel < ll)
                return;
        nfs3_stat_to_errstr (xid, nfs3op_strings[op].str, stat, pstat, errstr, sizeof (errstr));
        gf_log (GF_NFS3, ll, "%s", errstr);
}