int g_make_string_buffer(const char *str, gss_buffer_t buffer)
{
    if (buffer == GSS_C_NO_BUFFER)
        return (1);

    buffer->length = strlen(str);

    if ((buffer->value = gssalloc_strdup(str)) == NULL) {
        buffer->length = 0;
        return(0);
    }

    return(1);
}