keydb_set_ephemeral (KEYDB_HANDLE hd, int yes)
{
  int i;

  if (!hd)
    return 0;

  if (hd->use_keyboxd)
    return 0; /* FIXME: No support yet.  */


  yes = !!yes;
  if (hd->is_ephemeral != yes)
    {
      for (i=0; i < hd->used; i++)
        {
          switch (hd->active[i].type)
            {
            case KEYDB_RESOURCE_TYPE_NONE:
              break;
            case KEYDB_RESOURCE_TYPE_KEYBOX:
              keybox_set_ephemeral (hd->active[i].u.kr, yes);
              break;
            }
        }
    }

  i = hd->is_ephemeral;
  hd->is_ephemeral = yes;
  return i;
}