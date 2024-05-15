parse_pkcs5_algorithm(LIBSSH2_SESSION *session, pkcs5params *pkcs5,
                      asn1Element *algid, pkcs5algo **algotable)
{
    asn1Element oid;
    asn1Element param;
    char *cp;

    cp = getASN1Element(&oid, algid->beg, algid->end);
    if(!cp || *oid.header != ASN1_OBJ_ID)
        return -1;
    param.header = NULL;
    if(cp < algid->end)
        cp = getASN1Element(&param, cp, algid->end);
    if(cp != algid->end)
        return -1;
    for(; *algotable; algotable++)
        if(!oidcmp(&oid, (*algotable)->oid))
            return (*(*algotable)->parse)(session, pkcs5, *algotable,
                                          param.header? &param: NULL);
    return -1;
}