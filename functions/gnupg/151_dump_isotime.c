dump_isotime (const gnupg_isotime_t t)
{
  if (!t || !*t)
    log_printf ("%s", _("[none]"));
  else
    log_printf ("%.4s-%.2s-%.2s %.2s:%.2s:%s",
                t, t+4, t+6, t+9, t+11, t+13);
}