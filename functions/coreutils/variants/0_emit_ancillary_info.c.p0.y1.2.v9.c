void emit_ancillary_info (const char *program)
{
    const struct { char const *program; char const *node; } info_arr[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
    };

  const char* node_ptr = program;
  const struct infomap* program_map = infomap;

  while (program_map->program != nullptr && !STREQ (program, program_map->program)) 
    program_map++;

  node_ptr = program_map->node ? program_map->node : node_ptr;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char* messages_ptr = setlocale (LC_MESSAGES, nullptr);
  if (messages_ptr && STRNCMP_LIT (messages_ptr, "en_"))
  {
      fputs(_("Report any translation bugs to "
         "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = (!STREQ (program, "[")) ? program : "test";
  printf (_("Full documentation <%s%s>\n"),
    PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
    node_ptr, node_ptr == program ? " invocation" : "");
}