void emit_ancillary_info(char const *program_name)
{
  /* Define struct infomap holding current program and relevant online info */
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  /* Set pointers to start location */
  const char *help_topic = program_name;
  const struct infomap *prog_map_pointer = infomap;

  /* Until the program name is located in infomap, keep moving pointer to next node */
  while (prog_map_pointer->program && strcmp (program_name, prog_map_pointer->program) != 0)
    prog_map_pointer++;

  if (prog_map_pointer->node)
    help_topic = prog_map_pointer->node;

  /* General online/info URI output */
  printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

  /* If language/locale isn't 'en' or English, invite them to report translation errors */
  char const *current_locale = setlocale (LC_MESSAGES, nullptr);
  if (current_locale && strncmp (current_locale, "en_", 3) != 0)
    {
      puts ("Report any translation bugs to <https://translationproject.org/team/>\n");
    }

  const char *url_endpoint = strcmp (program_name, "[") == 0 ? "test" : program_name;
  printf ("Full documentation <%s%s>\n", PACKAGE_URL, url_endpoint);
  printf ("or available locally via: info '(coreutils) %s%s'\n", help_topic, help_topic == program_name ? " invocation" : "");
}