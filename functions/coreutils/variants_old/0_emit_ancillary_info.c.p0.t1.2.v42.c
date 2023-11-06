1. Change initialization of "node":

Using the given program value directly for "node" unless overridden by the "infomap" array.


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" }
  };

  char const *node = program;
  for (struct infomap const *map_prog = infomap; map_prog->program; ++map_prog)
    if (STREQ (program, map_prog->program))
      node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    fputs (_("Report translation bugs to <https://translationproject.org/team/>\n"), stdout);

  char const *url_program = program;
  if (STREQ (program, "[")) url_program = "test";

  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


2. Simplify string comparison for url_program:

Using conditional operator directly for the assignment of url_program to make it more concise.


void emitAncillaryInfo(char const *program)
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

  while (map_prog->program && !STREQ(program, map_prog->program)) map_prog++;
  if (map_prog->node) node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
      fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ(program, "[") ? "test" : program;
  printf (_("Documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
