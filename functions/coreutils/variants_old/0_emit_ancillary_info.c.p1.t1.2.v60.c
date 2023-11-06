emit_ancillary_info (char const *program)
{
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } 
  const infomap[] =
  {
    { "[", "test invocation" },
    { "coreutils", "Multi-prog invocation" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;
  while (map_prog->program)
  {
    if (! STREQ (program, map_prog->program))
    {
        map_prog++;
    }
    else break;
  }
  if (map_prog->node != nullptr) node = map_prog->node;
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  fputs(lc_messages != nullptr && STRNCMP_LIT (lc_messages, "en_") ? _("Report any translation bugs to "
               "<https://translationproject.org/team/>\n") : "", stdout);

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), 
    node, STREQ(node, program) ? " invocation" : "");
}