append_to_strlist( strlist_t *list, const char *string )
{
  strlist_t sl;
  sl = append_to_strlist_try (list, string);
  if (!sl)
    xoutofcore ();
  return sl;
}