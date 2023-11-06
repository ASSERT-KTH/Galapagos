void emit_ancillary_info (char const *program)
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
  struct infomap const *ptr_map_prog;
  for (ptr_map_prog = infomap; ptr_map_prog->program; ++ptr_map_prog)
  {
    if (strcmp(program, ptr_map_prog->program) == 0) {
      node = ptr_map_prog->node;
      break;
    }
  }
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strncmp(lc_messages, "en_", sizeof("en_")-1))
  {
    fputs (_("Report any translation bugs to ""<https://translationproject.org/team/>\n"), stdout);
  }
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, 
          strcmp(program, "[") == 0 ? "test" : program);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}