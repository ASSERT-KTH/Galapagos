krb5_pac_verify(krb5_context context,
                const krb5_pac pac,
                krb5_timestamp authtime,
                krb5_const_principal principal,
                const krb5_keyblock *server,
                const krb5_keyblock *privsvr)
{
    return krb5_pac_verify_ext(context, pac, authtime, principal, server,
                               privsvr, FALSE);
}