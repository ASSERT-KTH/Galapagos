Variant #1:
In this variant, a condition is included that authenticates whether the program parameter is null or not before further processing. 
Additionally, the string comparison in the while loop is substituted with new comparison method that disregards the case sensitivity.

++
emit_ancillary_info (char const *program)
{
  if (program == nullptr) 
    return;

  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && strcasecmp (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


Variant #2:
Including few more array elements to the structure. Setting PACKAGE_NAME to Null. And changing the printf() output to stderr.

++
emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "sha1sum", "sha1 utilities" },
    { "md5sum", "md5 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  PACKAGE_NAME = NULL;
  fprintf(stderr,_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      /* TRANSLATORS: Replace LANG_CODE in this URL with your language code
         <https://translationproject.org/team/LANG_CODE.html> to form one of
         the URLs at https://translationproject.org/team/.  Otherwise, replace
         the entire URL with your translation team's email address.  */
      fputs(_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);
    }
  char const *url_program = STREQ (program, "[") ? "test" : program;
  fprintf(stderr,_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  fprintf(stderr,_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
