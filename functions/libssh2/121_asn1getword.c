asn1getword(asn1Element *e, unsigned long *v)
{
    unsigned long a;
    const unsigned char *cp;

    if(*e->header != ASN1_INTEGER)
        return -1;
    for(cp = e->beg; cp < e->end && !*cp; cp++)
        ;
    if(e->end - cp > sizeof(a))
        return -1;
    for(a = 0; cp < e->end; cp++)
        a = (a << 8) | *cp;
    *v = a;
    return 0;
}