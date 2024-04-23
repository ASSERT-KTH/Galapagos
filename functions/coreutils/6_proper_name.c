proper_name (const char *name)
{
  /* See whether there is a translation.   */
  const char *translation = gettext (name);

  if (translation != name)
    {
      /* See whether the translation contains the original name.  */
      if (mbsstr_trimmed_wordbounded (translation, name))
        return translation;
      else
        {
          /* Return "TRANSLATION (NAME)".  */
          char *result =
            XNMALLOC (strlen (translation) + 2 + strlen (name) + 1 + 1, char);

          sprintf (result, "%s (%s)", translation, name);
          return result;
        }
    }
  else
    return name;
}