Function Variant 1:


emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "sha398sum", "sha3 utilities" },
    { "ld", "linker call invocation" },
    { "git", "git commands" },
    { "htop", "process viewer" },
    { nullptr, nullptr }
  };
  
  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n %s Extended Help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://bugs.translationproject.org/>\n"), stdout);
    }
 
  char const *url_program = STREQ (program, "ld") ? "linker" : program;
  printf (_("Complete knowledgebase is available at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or grab local access by: info '(coreutils) %s%s'\n"),
          node, node == program ? " execution details" : "");
}


Function Variant 2:


emit_ancillary_info(char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "openssl", "OpenSSL utilities" },
    { "vi", "VI editor commands" },
    { "nano", "nano editor commands" },
    { "tar", "archive utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && !STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nUser guide for %s: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
      fputs (_("Submit translation mistakes to "
               "<https://translation.bugreports.com/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "vi") ? "VI-Editor" : program;
  printf (_("Traditional documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or read it locally using: info '(coreutils) %s%s'\n"),
          node, node == program ? " guide" : "");
}
