asn1container(unsigned int type, ...)
{
    valiststr va;
    asn1Element *e;

    va_start(va.list, type);
    e = asn1containerv(type, va);
    va_end(va.list);
    return e;
}