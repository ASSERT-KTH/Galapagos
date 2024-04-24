gss_release_buffer (minor_status,
		    buffer)

OM_uint32 *		minor_status;
gss_buffer_t		buffer;
{
    if (minor_status)
	*minor_status = 0;

    /* if buffer is NULL, return */

    if(buffer == GSS_C_NO_BUFFER)
	return(GSS_S_COMPLETE);

    if ((buffer->length) &&
	(buffer->value)) {
	    gssalloc_free(buffer->value);
	    buffer->length = 0;
	    buffer->value = NULL;
    }

    return (GSS_S_COMPLETE);
}