__is_root_gfid (uuid_t gfid)
{
        uuid_t  root;

        memset (root, 0, 16);
        root[15] = 1;

        if (uuid_compare (gfid, root) == 0)
                return _gf_true;

        return _gf_false;
}