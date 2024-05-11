tlv_expect_object_id (tlv_parser_t tlv,
                      unsigned char const **r_oid, size_t *r_oidlen)
{
  const unsigned char *p;
  size_t n;

  tlv->lastfunc = __func__;
  if (!(tlv->ti.class == CLASS_UNIVERSAL && tlv->ti.tag == TAG_OBJECT_ID
        && !tlv->ti.is_constructed))
    return (tlv->lasterr = gpg_error (GPG_ERR_INV_OBJ));
  p = tlv->buffer;
  if (!(n=tlv->ti.length))
    return (tlv->lasterr = gpg_error (GPG_ERR_TOO_SHORT));

  *r_oid = p;
  *r_oidlen = tlv->ti.length;
  if (!(tlv->bufsize >= tlv->ti.length))
    return (tlv->lasterr = gpg_error (GPG_ERR_TOO_SHORT));
  tlv->buffer += tlv->ti.length;
  tlv->bufsize -= tlv->ti.length;
  return 0;
}