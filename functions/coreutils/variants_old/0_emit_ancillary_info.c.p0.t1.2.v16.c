Variant 1:

void emit_ancillary_info(char const* program) {
    // Info about each program
    struct infomap {
        char const* program;
        char const* node;
    } const infomap[] = {
    {"[", "Test Usage"},
    {"coreutils", "Bulk execution"},
    {"sha224sum", "SHA-2 utilities"},
    {"sha256sum", "SHA-2 utilities"},
    {"sha384sum", "SHA-2 utilities"},
    {"sha512sum", "SHA-2 utilities"},
    {nullptr, nullptr}};

    // Name of program or node in infomap
    char const* node = program;
    // Current selected program
    struct infomap const* inf_info = infomap;

    // Set value of node if program is found in infomap
    for (; inf_info->program && !STREQ(program, inf_info->program); inf_info++)
      ;

    // Use the program name if it exists in the map
    if (inf_info->node)
      node = inf_info->node;

    // Emit package information
    printf(_("Package %s help available here: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    // Print code of current locale
    char const* locale = setlocale(LC_MESSAGES, nullptr);

    // Print team's contact if locale isn't English
    if (locale && STRNCMP_LIT(locale, "en_"))
    {
        fputs(_("Send any translation errors here: "
                "<https://translationproject.org/team/>\n"),
                stdout);

    }

    // Use alias for symbolic link program
    char const* URL_program = STREQ(program, "[") ? "Test" : program;
    
    // Emit complete documentation
    printf(_("Detailed documentation here <%s%s>\n"),
            PACKAGE_URL, URL_program);

    // Print Info format of documentation if available in the system
    // Usually found in UNIX systems
    printf(_("or access locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " is called" : "");
 
}

Variant 2:


void emit_ancillary_info(char const* program) {

  struct infomap {
    char const* program;
    char const* node;
  } const infomap[] = {
    {"[", "Case Testing"},
    {"coreutils", "Multi-run mode"},
    {"sha224sum", "sha2 suite"},
    {"sha256sum", "sha2 suite"},
    {"sha384sum", "sha2 suite"},
    {"sha512sum", "sha2 suite"},
    {nullptr, nullptr}
  };

  char const* node = program;
  struct infomap const* map_link = infomap;

  for (; map_link->program && ! STREQ (program, map_link->program); map_link++)
     ;

  if (map_link->node)
    node = map_link->node;

  printf (_("\nPackage %s help can be found here: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const* lc_messages = setlocale(LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT(lc_messages, "en_")) 
  {
    fputs (_("Please report translation errors to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const* url_program = (STREQ(program, "[")) ? "Case_Test" : program;
  printf (_("Detailed documentation for this package: <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally by entering: info '(coreutils) %s%s'\n"),
          node, (node == program) ? " seciton" : "");
}

