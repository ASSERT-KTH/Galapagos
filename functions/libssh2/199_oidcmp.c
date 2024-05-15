oidcmp(const asn1Element *e, const unsigned char *oid)
{
    int i = e->end - e->beg - *oid++;

    if(*e->header != ASN1_OBJ_ID)
        return -2;
    if(!i)
        i = memcmp(e->beg, oid, oid[-1]);
    return i;
}