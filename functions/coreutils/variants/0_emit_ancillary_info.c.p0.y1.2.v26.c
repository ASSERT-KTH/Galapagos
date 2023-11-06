
void emit_ancillary_info (char const *program)
{
  struct infomap
  {
    char const *program;
    char const *node;
  } const lookup[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const * map_ptr = lookup;

  while (map_ptr->program && strcmp(program, map_ptr->program) != 0)
    map_ptr++;

  if (map_ptr->node)
    node = map_ptr->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_param = setlocale (LC_MESSAGES, nullptr);
  if (lc_param && strncmp(lc_param, "en_",2) != 0)
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = strcmp(program, "[") == 0 ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
