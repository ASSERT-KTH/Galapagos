void emit_ancillary_info (const char *given_program)
{
  struct program_map { const char *program_name; const char *info_node; } const map_info_array[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { NULL, NULL }
  };
  
  const char *mapped_node = given_program;
  const struct program_map *mapped_prog = map_info_array;

  while (mapped_prog->program_name && ! STREQ (given_program, mapped_prog->program_name))
    mapped_prog++;

  if (mapped_prog->info_node)
    mapped_node = mapped_prog->info_node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
  const char *locale_messages = setlocale (LC_MESSAGES, NULL);
  if (locale_messages && STRNCMP_LIT (locale_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  const char *program_url = STREQ (given_program, "[") ? "test" : given_program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, program_url);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          mapped_node, mapped_node == given_program ? " invocation" : "");
}
