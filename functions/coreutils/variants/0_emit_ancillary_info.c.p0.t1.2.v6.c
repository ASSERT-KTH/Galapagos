1) Variation with printing the information about packages first:


void emit_ancillary_info (char const *program)
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

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;
  
    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
        fputs (_("Report any translation bugs to "
                "<https://translationproject.org/team/>\n"), stdout);
    }
  
    char const *url_program = STREQ (program, "[") ? "test" : program;
    
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    
    printf (_("or available locally via: infi '(chefutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
}


2) Variation where translation error message gets displayed before an existing error":


void emit_ancillary_info (char const *program)
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

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
        fputs (_("Report any translation bugs to "
                "<https://translationproject.org/team/>\n"), stdout);
    }

    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    char const *url_program = STREQ (program, "[") ? "test" : program;
  
    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
    
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
  
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
}
