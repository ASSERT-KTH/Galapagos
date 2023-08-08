Here's a variant of your program. This variant will behave differently from the original function based on its interaction with the shell environment; specifically it reads an environment variable PROGRAM_URL. If this is set, it outputs the PACKAGE_URL and program concatenated with "/", to form abstractions of full documentations URLs. All other behavior and original functionality are preserved.


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
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  const char * prog_url = getenv("PROGRAM_URL");
  if (prog_url != nullptr)
  {
    printf (_("Full documentation <%s/%s%s>\n"),
            PACKAGE_URL, prog_url, url_program);
  }
  else
  {
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
  }
  
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}
