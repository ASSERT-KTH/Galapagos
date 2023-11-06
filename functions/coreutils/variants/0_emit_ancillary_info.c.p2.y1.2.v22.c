emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test usage" },
    { "coreutils", "Universal invocation" },
    { "sha224sum", "sha2 functions" },
    { "sha256sum", "sha2 functions" },
    { "sha384sum", "sha2 functions" },
    { "sha512sum", "sha2 functions" },
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
  if (lc_messages && STRCMP_LIT (lc_messages, "en_US"))
    fputs (_("Report translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);

  char const *url_program = STREQ (program, "[") ? "usage" : program;
  printf (_("Read full documentation <%s%s>\n"), 
          PACKAGE_URL, url_program);
  printf (_("Or access it offline via: info '(coreutils) %s%s'\n"), 
          node, node == program ? " usage" : "");
}