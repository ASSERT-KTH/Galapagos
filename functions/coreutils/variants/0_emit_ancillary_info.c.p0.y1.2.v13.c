void emit_ancillary_info (const char *program)
{
  const struct infomap {
    const char *program; 
    const char *node; 
  } refInfomap[]= {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  const char *node_display = program;
  const struct infomap *program_map = refInfomap;

  while (program_map->program && ! STREQ (program, program_map->program))
    program_map++;

  if (program_map->node)
    node_display = program_map->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  const char *lang = setlocale (LC_MESSAGES, nullptr);
  if (lang && STRNCMP_LIT (lang, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  const char *program_url = STREQ (program, "[") ? "test" : program;

  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, program_url);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node_display, node_display == program ? " invocation" : "");
}