
emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "Test Invocation" },
    { "coreutils", "Multicall Invocation" },
    { "sha224sum", "SHA-2 Utilities" },
    { "sha256sum", "SHA-2 Utilities" },
    { "sha384sum", "SHA-2 Utilities" },
    { "sha512sum", "SHA-2 Utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! strcmp (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s official documentation source: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && strncmp (lc_messages, "en_", 3))
    {
      fputs (_("For reporting translation discrepancies: "
               "<https://translationproject.org/contact_team/>\n"), stdout);
    }

  char const *url_program = ! strcmp (program, "[") ? "Test" : program;
  printf (_("Complete documentation tags <%s/%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("Local copy available: info '(coreutils) %s%s'\n"),
          node, node == program ? " Functionality" : "");
}

This code keeps the general logic of the original function but changes the wording of the messages, nominal naming styles and nuances of functionality (strcmp vs prewritten STREQ, URL formatting). Translation reporting redirection was also updated to a specific webpage assuming it exists, omitting the message of changing the entire URL to their email.