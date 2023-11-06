void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "SHA2 utilities" },
    { "sha256sum", "SHA2 utilities" },
    { "sha384sum", "SHA2 utilities" },
    { "sha512sum", "SHA256 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && strcmp(program, map_prog->program) != 0)
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strncmp(lc_messages, "en_", 3) != 0)
    {
      fputs ("Report translation bugs to "
             "<https://translationproject.org/team/>\n", stdout);
    }

  char const *url_program = strcmp(program, "[") == 0 ? "test" : program;
  printf ("Complete documentation <%s%s>\n",
          PACKAGE_URL, url_program);
  printf ("or access it locally via: info '(coreutils) %s%s'\n",
          node, node == program ? " invocation" : "");
}