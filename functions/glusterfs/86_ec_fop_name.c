const char * ec_fop_name(int32_t id)
{
    if (id >= 0)
    {
        return gf_fop_list[id];
    }

    return ec_fop_list[-id];
}