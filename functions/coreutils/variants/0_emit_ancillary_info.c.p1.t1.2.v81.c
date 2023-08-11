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

  for (; map_prog->program; ++map_prog)
    if (STREQ (program, map_prog->program))
    {
      node = map_prog->node;
      break;
    }
 
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "us_"))
   {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),
  url_program[0]=='['?"test":url_program);
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node[0]=='['?"test":node, node == url_program ? " invocation" : "");
}