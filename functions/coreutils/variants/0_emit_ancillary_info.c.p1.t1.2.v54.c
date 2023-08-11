void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Common commands" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "Security utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  do {
    if (STREQ (program, map_prog->program)){
      node = map_prog->node;
      break;
      }
    map_prog++;
  } while (map_prog->program);
  

  printf (_("\n%s online assistance: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  char const *URLProgram = STREQ (program, "[") ? "test" : program;
  printf (_("Additional documentation <%s%s>\n"),
          PACKAGE_URL, URLProgram);
  printf (_("Also locally accessible: info '(coreutils) %s%s'\n"),
          node, node == program ? " instructions" : "");
}