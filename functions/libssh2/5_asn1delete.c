asn1delete(asn1Element *e)
{
    if(e) {
        if(e->header)
            free((char *) e->header);
        free((char *) e);
    }
}