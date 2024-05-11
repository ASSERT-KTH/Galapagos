copy_public_key (PKT_public_key *d, PKT_public_key *s)
{
  d = copy_public_key_basics (d, s);
  d->user_id = scopy_user_id (s->user_id);
  d->prefs = copy_prefs (s->prefs);

  if (!s->revkey && s->numrevkeys)
    BUG();
  if (s->numrevkeys)
    {
      d->revkey = xmalloc(sizeof(struct revocation_key)*s->numrevkeys);
      memcpy(d->revkey,s->revkey,sizeof(struct revocation_key)*s->numrevkeys);
    }

  if (s->serialno)
    d->serialno = xstrdup (s->serialno);
  if (s->updateurl)
    d->updateurl = xstrdup (s->updateurl);

  return d;
}