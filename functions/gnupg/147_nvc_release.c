nvc_release (nvc_t pk)
{
  nve_t e, next;

  if (pk == NULL)
    return;

  for (e = pk->first; e; e = next)
    {
      next = e->next;
      nve_release (e, pk->private_key_mode);
    }

  xfree (pk);
}