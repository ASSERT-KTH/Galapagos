_gcry_md_reset (gcry_md_hd_t a)
{
  GcryDigestEntry *r;

  /* Note: We allow this even in fips non operational mode.  */

  a->bufpos = a->ctx->flags.finalized = 0;

  if (a->ctx->flags.hmac)
    for (r = a->ctx->list; r; r = r->next)
      {
        memcpy (r->context, (char *)r->context + r->spec->contextsize,
                r->spec->contextsize);
      }
  else
    for (r = a->ctx->list; r; r = r->next)
      {
        memset (r->context, 0, r->spec->contextsize);
        (*r->spec->init) (r->context,
                          a->ctx->flags.bugemu1? GCRY_MD_FLAG_BUGEMU1:0);
      }
}