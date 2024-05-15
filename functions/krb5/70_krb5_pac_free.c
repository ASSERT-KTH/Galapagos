krb5_pac_free(krb5_context context, krb5_pac pac)
{
    if (pac != NULL) {
        zapfree(pac->data.data, pac->data.length);
        free(pac->buffers);
        zapfree(pac, sizeof(*pac));
    }
}