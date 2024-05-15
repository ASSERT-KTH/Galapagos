get_handle(char *client)
{
    void *handle;
    char *service, *pass;

    if (client == NULL)
        return NULL;

    if (*client == '$') {
        service = KADM5_CHANGEPW_SERVICE;
        client++;
    } else {
        service = KADM5_ADMIN_SERVICE;
    }
    pass = (strcmp(client, "user") == 0) ? USER_PASSWORD : ADMIN_PASSWORD;

    check(kadm5_init(context, client, pass, service, NULL,
                     KADM5_STRUCT_VERSION, api, NULL, &handle));
    return handle;
}