1. Updating the infomap with additional programs:


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "md5sum", "hashsum utilities" },
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

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_", 3))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


2. Specifying the size comparison value for the STRNCMP_LIT function:


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

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_", 3))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}