Here's a variant of the function which maintains the original functionality but adds the behavior of logging the information about the program to a file.


emit_ancillary_info (char const *program)
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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

      
  FILE *log_file;

  log_file = fopen("log.txt", "a");
  fprintf (log_file, _("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  fclose(log_file);

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);

  log_file = fopen("log.txt", "a");
  fprintf (log_file, _("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  fclose(log_file);

  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");

  log_file = fopen("log.txt", "a");
  fprintf (log_file, _("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
  fclose(log_file);
}
