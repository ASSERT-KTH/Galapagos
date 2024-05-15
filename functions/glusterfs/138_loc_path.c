loc_path (loc_t *loc, const char *bname)
{
        int     ret = 0;

        if (loc->path)
                goto out;

        ret = -1;

        if (bname && !strlen (bname))
                bname = NULL;

        if (!bname)
                goto inode_path;

        if (loc->parent && !uuid_is_null (loc->parent->gfid)) {
                ret = inode_path (loc->parent, bname, (char**)&loc->path);
        } else if (!uuid_is_null (loc->pargfid)) {
                ret = gf_asprintf ((char**)&loc->path, INODE_PATH_FMT"/%s",
                                   uuid_utoa (loc->pargfid), bname);
        }

        if (loc->path)
                goto out;

inode_path:
        if (loc->inode && !uuid_is_null (loc->inode->gfid)) {
                ret = inode_path (loc->inode, NULL, (char **)&loc->path);
        } else if (!uuid_is_null (loc->gfid)) {
                ret = gf_asprintf ((char**)&loc->path, INODE_PATH_FMT,
                                   uuid_utoa (loc->gfid));
        }
out:
        return ret;
}