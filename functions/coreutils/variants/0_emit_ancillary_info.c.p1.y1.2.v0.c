1. Changing variable names


emit_ancillary_info (char const *prg)
{
  struct map { char const *prg; char const *n; } const map[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *n = prg;
  struct map const *map_prg = map;

  while (map_prg->prg && ! STREQ (prg, map_prg->prg))
    map_prg++;

  if (map_prg->n)
    n = map_prg->n;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);
    
  char const *url_prg = STREQ (prg, "[") ? "test" : prg;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_prg);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),  n, n == prg ? 
  " invocation" : "");
}


2. Rearrange the Structure 


emit_ancillary_info (char const *program)
{
  struct map { char const *program; char const *node; } const map_list[] = {
    { "sha384sum", "sha2 utilities" },
    { "coreutils", "Multi-call invocation" },
    { "sha256sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { "sha224sum", "sha2 utilities" },
    { "[", "test invocation" },
    { nullptr, nullptr }
  };

  char const *node_addr = program;
  struct map const *p_map = map_list;

  while (p_map->program && ! STREQ (program, p_map->program))
    p_map++;

  if (p_map->node)
    node_addr = p_map->node;

  char const *curr_locale = setlocale (LC_MESSAGES, nullptr);
  if (curr_locale && STRNCMP_LIT (curr_locale, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);
    
  char const *program_url = STREQ (program, "[") ? "test" : program;
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, program_url);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),  node_addr, node_addr == program ? " invocation" : "");
}
