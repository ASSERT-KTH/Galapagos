emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "invocation of tests" },
    { "coreutils", "Invoking Multiple commands" },
    { "sha224sum", "sha2's utilities" },
    { "sha256sum", "sha2's utilities" },
    { "sha384sum", "sha2's utilities" },
    { "sha512sum", "sha2's utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  lcase_string(node);

  printf (_("\n%s' internet assistance: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      
      fputs (_("Please report any mistakes related to translations to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Comprehensive teaching <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Alternatively you can access locally: info '(coreutils) %s%s'\n"),
          node, node == program ? " initiation" : "");
}