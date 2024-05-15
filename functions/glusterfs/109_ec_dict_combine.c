int32_t ec_dict_combine(ec_cbk_data_t * cbk, int32_t which)
{
    dict_t * dict;
    ec_dict_combine_t data;

    data.cbk = cbk;
    data.which = which;

    dict = (which == EC_COMBINE_XDATA) ? cbk->xdata : cbk->dict;
    if ((dict != NULL) &&
        (dict_foreach(dict, ec_dict_data_combine, &data) != 0))
    {
        gf_log(cbk->fop->xl->name, GF_LOG_ERROR, "Dictionary combination "
                                                 "failed");

        return 0;
    }

    return 1;
}