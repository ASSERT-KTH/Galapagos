emit_ancillary_info (char const *programName)
{
  struct info { char const *usedProgram; char const *relatedNode; } const information[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = programName;
  struct info const *structure = information;

  while (structure->usedProgram && ! STREQ (programName, structure->usedProgram))
    structure++;

  if (structure->relatedNode)
    node = structure->relatedNode;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  
  char const *langLocale = setlocale (LC_MESSAGES, nullptr);
  if (langLocale && STRNCMP_LIT (langLocale, "en_"))
    {
      
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *programURL = STREQ (programName, "[") ? "test" : programName;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, programURL);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == programName ? " invocation" : "");
}

---------------------------------------------------------------------------------------------------------------------------

Resource_ancillary_details (char const *program_main)
{
  struct main_info { char const *software_app; char const *node_main; } const main_data[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node_main = program_main;
  struct main_info const *table_program = main_data;

  while (table_program->software_app && ! STREQ (program_main, table_program->software_app))
    table_program++;

  if (table_program->node_main)
    node_main = table_program->node_main;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *messages_locale = setlocale (LC_MESSAGES, nullptr);
  if (messages_locale && STRNCMP_LIT (messages_locale, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  char const *actual_program_url = STREQ (program_main, "[") ? "test" : program_main;
  printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, actual_program_url);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node_main, node_main == program_main ? " invocation" : "");
}