void emit_ancillary_info (const char *program)
{
   struct infomap { const char *program; const char *node; } const infomapArray[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { 0, 0 },
  };

  const char *node = program;
  const struct infomap *map_entry;

  for (map_entry = infomapArray; map_entry->program && strcmp (program, map_entry->program) != 0; map_entry++)
  {  } 

  if (map_entry->node) 
    node = map_entry->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *locale_str = setlocale (LC_MESSAGES, 0);
 
  if (locale_str && strncmp (locale_str, "en_", strlen("en_")) != 0)
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  const char *final_program = strcmp (program, "[") == 0 ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), 
          PACKAGE_URL,  final_program );

  printf (_("or available locally via: info '(coreutils) %s%s'\n"), 
             node, (node == program) ? " invocation" : "");
}