init_membuf (struct membuf *mb, int initiallen)
{
  mb->len = 0;
  mb->size = initiallen;
  mb->out_of_core = 0;
  mb->buf = xtrymalloc (initiallen);
  if (!mb->buf)
      mb->out_of_core = 1;
}