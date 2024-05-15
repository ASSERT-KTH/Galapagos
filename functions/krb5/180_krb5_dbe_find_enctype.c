krb5_dbe_find_enctype(krb5_context kcontext, krb5_db_entry *dbentp,
                      krb5_int32 ktype, krb5_int32 stype, krb5_int32 kvno,
                      krb5_key_data **kdatap)
{
    krb5_int32 start = 0;
    return krb5_dbe_search_enctype(kcontext, dbentp, &start, ktype, stype,
                                   kvno, kdatap);
}