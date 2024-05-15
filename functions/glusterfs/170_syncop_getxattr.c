syncop_getxattr (xlator_t *subvol, loc_t *loc, dict_t **dict, const char *key,
                 dict_t *xdata)
{
        struct syncargs args = {0, };

        SYNCOP (subvol, (&args), syncop_getxattr_cbk, subvol->fops->getxattr,
                loc, key, xdata);

        if (dict)
                *dict = args.xattr;
        else if (args.xattr)
                dict_unref (args.xattr);

        if (args.op_ret < 0)
                return -args.op_errno;
        return args.op_ret;
}