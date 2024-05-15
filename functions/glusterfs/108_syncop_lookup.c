syncop_lookup (xlator_t *subvol, loc_t *loc, dict_t *xdata_req,
               struct iatt *iatt, dict_t **xdata_rsp, struct iatt *parent)
{
        struct syncargs args = {0, };

        SYNCOP (subvol, (&args), syncop_lookup_cbk, subvol->fops->lookup,
                loc, xdata_req);

        if (iatt)
                *iatt = args.iatt1;
        if (parent)
                *parent = args.iatt2;
        if (xdata_rsp)
                *xdata_rsp = args.xdata;
        else if (args.xdata)
                dict_unref (args.xdata);

        if (args.op_ret < 0)
                return -args.op_errno;
        return args.op_ret;
}