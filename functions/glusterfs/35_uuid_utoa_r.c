uuid_utoa_r (uuid_t uuid, char *dst)
{
        if(!dst)
                return NULL;
        uuid_unparse (uuid, dst);
        return dst;
}