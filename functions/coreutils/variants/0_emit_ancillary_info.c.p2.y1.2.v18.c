emit_ancillary_info (char const *program)
{
  struct infomap { 
      char const *program; 
      char const *node; 
  } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "[", "test invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  char const *node = map_prog->node ? map_prog->node : program;

  /* Don't output this redundant message for English locales.
     Note we still output for 'C' so that it gets included in the man page.  */
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
    
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  /* .htaccess on the coreutils web site maps programs to the appropriate page,
     however we explicitly handle "[" -> "test" here as the "[" is not
     recognized as part of a URL by default in terminals.  */
  char const *url_program = STREQ (program, "[") ? program : "test";

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node == program ? " invocation" : "", node);

  fflush(stdout);
}