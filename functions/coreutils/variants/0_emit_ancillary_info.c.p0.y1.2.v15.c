void emit_ancillary_info (char const *inputProgram)
{
  struct mapping_info { char const *actual_program; char const *documentation_node; };
  static const struct mapping_info information_map[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *presentNode = inputProgram;
  struct mapping_info const *mappingProgram = information_map;

  while (mappingProgram->actual_program && strcmp (inputProgram, mappingProgram->actual_program) != 0)
    mappingProgram++;

  if (mappingProgram->documentation_node)
    presentNode = mappingProgram->documentation_node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *current_locale = setlocale (LC_MESSAGES, 0);

  if (current_locale && strncmp(current_locale, "en_", 3))
    {
      fputs (_("Report any translation bugs to "
	       "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *altered_program = strcmp (inputProgram, "[") == 0 ? "test" : inputProgram;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, altered_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
         presentNode, presentNode == inputProgram ? " invocation" : "");
}