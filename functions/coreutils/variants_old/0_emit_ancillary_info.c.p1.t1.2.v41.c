Here is a program variant of the above function that changes the behavior of the original function but maintains its original functionality. The behavior change that was introduced is that now when the 'program' parameter is not in the 'infomap' array, the function generates an URL with the 'program' as the subpath, instead of just printing package information as in the original version.


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
  struct infomap const *map_prog = infomap;

  int found = 0;
  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node) {
    node = map_prog->node;
    found = 1;
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;

  if (found)
  {
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
  }
  else
  {
    printf (_("Full documentation <%s%s>\n"), 
            PACKAGE_URL, url_program);
  }
}


This variant now checks whether 'map_prog->node' was found. If it wasn't, which implicates that 'program' was not encountered in the 'infomap' array, it only outputs a generated URL with 'program' as the subpath.