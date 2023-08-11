1. Variant with modified printing order:

emit_ancillary_info (char const *program)
{
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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  /* .htaccess on the coreutils web site maps programs to the appropriate page,
     however we explicitly handle "[" -> "test" here as the "[" is not
     recognized as part of a URL by default in terminals.  */

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) 
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


2. Variant with the URL appended to every output statement.

emit_ancillary_info (char const *program)
{
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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n%s"),
          PACKAGE_NAME, PACKAGE_URL, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n%s", PACKAGE_URL), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n%s"),
          PACKAGE_URL, url_program, PACKAGE_URL);
  printf (_("or available locally via: info '(coreutils) %s%s'\n%s"),
          node, node == program ? " invocation" : "", PACKAGE_URL);
}
