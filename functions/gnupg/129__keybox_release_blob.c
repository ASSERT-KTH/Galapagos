_keybox_release_blob (KEYBOXBLOB blob)
{
  int i;
  if (!blob)
    return;
  if (blob->buf)
    {
      size_t len;
      xfree (get_membuf (blob->buf, &len));
    }
  xfree (blob->keys );
  xfree (blob->serialbuf);
  for (i=0; i < blob->nuids; i++)
    xfree (blob->uids[i].name);
  xfree (blob->uids );
  xfree (blob->sigs );
  xfree (blob->blob );
  xfree (blob );
}