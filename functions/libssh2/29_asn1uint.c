asn1uint(_libssh2_bn *bn)
{
    asn1Element *e;
    int bits;
    int length;
    unsigned char *p;

    if(!bn)
        return NULL;

    bits = _libssh2_bn_bits(bn);
    length = (bits + 8) >> 3;
    e = asn1_new(ASN1_INTEGER, length);

    if(e) {
        p = e->beg;
        if(!(bits & 0x07))
            *p++ = 0;
        _libssh2_bn_to_bin(bn, p);
    }

    return e;
}