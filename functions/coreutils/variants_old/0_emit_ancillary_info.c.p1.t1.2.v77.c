Here's one way to modify the reference implementation, while preserving the original behavior: it adds a count of how many times the function was invoked since first being called.


void emit_ancillary_info (char const *program)
{
  static int call_count = 0;  // keeps track of number of function invocations
  call_count++;

  struct infomap {
      char const *program; 
      char const *node; 
    } const infomap[] = {
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

  printf (_("\n%s online help: <%s> [Called: %d time(s)]\n"), PACKAGE_NAME, PACKAGE_URL, call_count);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

This modification precedes the original ancillary text with tracking information, which is the count of how many times the function has already been invoked. This doesn't create any auxiliary functions or helper functions, remains to have the same function signature, and fully accomplishes all tasks of the original function.