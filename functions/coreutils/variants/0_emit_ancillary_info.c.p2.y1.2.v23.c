
emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "generic invocation" },
    { "sha224sum", "sha3 utilities" },
    { "sha256sum", "sha3 utilities" },
    { "sha384sum", "sha3 utilities" },
    { "sha512sum", "sha3 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;
  
  printf (_("\n%s web help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Send translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;

  printf (_("In Depth documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  printf (_("or check locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " Invocation" : "");
}

The changes to the program:
1. Changed the 'node' mapping of 'coreutils' and SHAs in 'infomap' function.
2. Changed "online help" to "web help".
3. Changed "Report any translation bugs" to "Send translation bugs" to remove an indirect plea.
4. Very slightly altered the guidance for using locally stored docs for better understanding to user.