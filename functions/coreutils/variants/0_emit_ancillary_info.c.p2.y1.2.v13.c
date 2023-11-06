void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "md5sum", "hash utilities" },
    { "base64", "base64 utilities" },
    { "cat", "file utilities" },
    { "chmod", "file permissions utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && strcmp (program, map_prog->program) != 0)
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strlen(lc_messages) > 3 && lc_messages[2] == '_')
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = strcmp (program, "[") == 0 ? "test" : program;
  printf (_("Full documentation <%s%s appended info here>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, strcmp(node, program) == 0 ? " guide" : "");
}