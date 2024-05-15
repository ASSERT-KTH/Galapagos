krb5_free_ticket(krb5_context context, krb5_ticket *val)
{
    if (val == NULL)
        return;
    krb5_free_principal(context, val->server);
    free(val->enc_part.ciphertext.data);
    krb5_free_enc_tkt_part(context, val->enc_part2);
    free(val);
}