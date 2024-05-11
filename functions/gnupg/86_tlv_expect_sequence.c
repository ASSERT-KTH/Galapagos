tlv_expect_sequence (tlv_parser_t tlv)
{
  tlv->lastfunc = __func__;
  if (!(tlv->ti.class == CLASS_UNIVERSAL && tlv->ti.tag == TAG_SEQUENCE
        && tlv->ti.is_constructed))
    return (tlv->lasterr = gpg_error (GPG_ERR_INV_OBJ));
  return _tlv_push (tlv);
}