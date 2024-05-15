asn1bytes(unsigned int type, const unsigned char *bytes, unsigned int length)
{
    asn1Element *e;

    e = asn1_new(type, length);
    if(e && length)
        memcpy(e->beg, bytes, length);
    return e;
}