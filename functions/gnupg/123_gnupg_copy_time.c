gnupg_copy_time (gnupg_isotime_t d, const gnupg_isotime_t s)
{
  if (*s)
    {
      if ((strlen (s) != 15 || s[8] != 'T'))
        BUG();
      memcpy (d, s, 15);
      d[15] = 0;
    }
  else
    *d = 0;
}