emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test commands" },
    { "coreutils", "Single-call usage" },
    { "sha224sum", "sha2 tools" },
    { "sha256sum", "sha2 tools" },
    { "sha384sum", "sha2 tools" },
    { "sha512sum", "sha2 tools" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;
  
  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s offline help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation-related issues to "
               "<https://translationproject.org/crew/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Complete manual <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or obtain locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " usage" : "");
}