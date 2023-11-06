emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test commands" },
    { "coreutils", "Multi-invocation" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  for (; map_prog->program && ! STREQ (program, map_prog->program); map_prog++);

  if (map_prog->node)
    node = map_prog->node;

  printf (_("%s online support: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Send any translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Complete documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or check locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " commands" : "");
}