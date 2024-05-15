dht_inode_ctx_time_update (inode_t *inode, xlator_t *this, struct iatt *stat,
                           int32_t post)
{
        dht_inode_ctx_t         *ctx            = NULL;
        dht_stat_time_t         *time           = 0;
        int                      ret            = -1;

        GF_VALIDATE_OR_GOTO (this->name, stat, out);
        GF_VALIDATE_OR_GOTO (this->name, inode, out);

        ret = dht_inode_ctx_get (inode, this, &ctx);

        if (ret) {
                ctx = GF_CALLOC (1, sizeof (*ctx), gf_dht_mt_inode_ctx_t);
                if (!ctx)
                        return -1;
        }

        time = &ctx->time;

        DHT_UPDATE_TIME(time->mtime, time->mtime_nsec,
                        stat->ia_mtime, stat->ia_mtime_nsec, inode, post);
        DHT_UPDATE_TIME(time->ctime, time->ctime_nsec,
                        stat->ia_ctime, stat->ia_ctime_nsec, inode, post);
        DHT_UPDATE_TIME(time->atime, time->atime_nsec,
                        stat->ia_atime, stat->ia_atime_nsec, inode, post);

        ret = dht_inode_ctx_set (inode, this, ctx);
out:
        return 0;
}