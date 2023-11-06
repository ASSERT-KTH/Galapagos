void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; };
  
  struct infomap const infomap_mapping[] =
  {
    {"[", "test invocation"},
    {"coreutils", "Multi-call invocation"},
    {"sha224sum", "sha2 utilities"},
    {"sha256sum", "sha2 utilities"},
    {"sha384sum", "sha2 utilities"},
    {"sha512sum", "sha2 utilities"},
    {nullptr, nullptr}
  };

  char const *node_help = program;
  struct infomap const *info_prog_mapping = infomap_mapping;
  
  // Find and Set correct node
  for (; info_prog_mapping->program; ++info_prog_mapping)
  {
    if (STREQ (program, info_prog_mapping->program))
    {
      node_help = info_prog_mapping->node;
      break;
    }
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL );

  char const *languages = setlocale (LC_MESSAGES, nullptr);
  
  if (languages && STRNCMP_LIT (languages, "en_"))
    fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"),
            stdout);

  // Fixing title conflict on web browsers not interpreting "[" or "]" properly
  char const *fixed_output = STREQ (program, "[") ? "test" : program;

  // Display fixed_output for documentation link
  printf (_("Full documentation: <%s://%s/%s>\n"),
          "https", PACKAGE_URL, fixed_output);
          
  printf (_("or available locally via: info `(coreutils) %s%s'\n"),
          ( node_help ), ( node_help == program ? " invocation" : "" ) );
}