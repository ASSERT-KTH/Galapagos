krb5_free_cred_contents(krb5_context context, krb5_creds *val)
{
    if (val == NULL)
        return;
    krb5_free_principal(context, val->client);
    val->client = 0;
    krb5_free_principal(context, val->server);
    val->server = 0;
    krb5_free_keyblock_contents(context, &val->keyblock);
    free(val->ticket.data);
    val->ticket.data = 0;
    free(val->second_ticket.data);
    val->second_ticket.data = 0;
    krb5_free_addresses(context, val->addresses);
    val->addresses = 0;
    krb5_free_authdata(context, val->authdata);
    val->authdata = 0;
}