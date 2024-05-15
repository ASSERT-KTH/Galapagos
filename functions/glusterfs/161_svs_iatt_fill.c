svs_iatt_fill (uuid_t gfid, struct iatt *buf)
{
        struct timeval  tv    = {0, };
        xlator_t       *this  = NULL;

        this = THIS;

        GF_VALIDATE_OR_GOTO ("snapview-server", this, out);
        GF_VALIDATE_OR_GOTO (this->name, buf, out);

        buf->ia_type = IA_IFDIR;
        buf->ia_uid  = 0;
        buf->ia_gid  = 0;
        buf->ia_size = 0;
        buf->ia_nlink = 2;
        buf->ia_blocks = 8;
        buf->ia_size = 4096;

        uuid_copy (buf->ia_gfid, gfid);
        svs_fill_ino_from_gfid (buf);

        buf->ia_prot = ia_prot_from_st_mode (0755);

        gettimeofday (&tv, 0);

        buf->ia_mtime = buf->ia_atime = buf->ia_ctime = tv.tv_sec;
        buf->ia_mtime_nsec = buf->ia_atime_nsec = buf->ia_ctime_nsec =
                (tv.tv_usec * 1000);

out:
        return;
}