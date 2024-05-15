krb5_kt_get_entry(krb5_context context, krb5_keytab keytab,
                  krb5_const_principal principal, krb5_kvno vno,
                  krb5_enctype enctype, krb5_keytab_entry *entry)
{
    krb5_error_code err;
    krb5_principal_data princ_data;

    if (krb5_is_referral_realm(&principal->realm)) {
        char *realm;
        princ_data = *principal;
        principal = &princ_data;
        err = krb5_get_default_realm(context, &realm);
        if (err)
            return err;
        princ_data.realm.data = realm;
        princ_data.realm.length = strlen(realm);
    }
    err = krb5_x((keytab)->ops->get,(context, keytab, principal, vno, enctype,
                                     entry));
    TRACE_KT_GET_ENTRY(context, keytab, principal, vno, enctype, err);
    if (principal == &princ_data)
        krb5_free_default_realm(context, princ_data.realm.data);
    return err;
}