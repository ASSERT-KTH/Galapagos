void emit_ancillary_info (char const *program)
{
  struct infomap
  {
    char const *program;
    char const *node;
  } const infomap[] = {
      { "[", "test invocation" },
      { "coreutils", "Multi-call invocation" },
      { "sha224sum", "sha2 utilities" },
      { "sha256sum", "sha2 utilities" },
      { "sha384sum", "sha2 utilities" },
      { "sha512sum", "sha2 utilities" },
      { NULL, NULL }
  };

  const char *node = program;
  const struct infomap *prog_map = infomap;

  while (prog_map->program && strcmp(program, prog_map->program) != 0)
    prog_map++;

  node = (prog_map->node ? prog_map->node : node);
  
  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  const char *lc_messages = setlocale(LC_MESSAGES, NULL);

  if (lc_messages && strncmp(lc_messages, "en_", strlen("en_")) != 0) {
    puts("Report any translation bugs to <https://translationproject.org/team/>\n");
  }

  const char *prog_url = strcmp(program, "[") == 0 ? "test" : program;

  printf ("Full documentation at <%s%s>\n", PACKAGE_URL, prog_url);
  printf ("or available locally via: info '(coreutils) %s%s'\n", 
          node, strcmp(node, program) == 0 ? " invocation" : "");
}