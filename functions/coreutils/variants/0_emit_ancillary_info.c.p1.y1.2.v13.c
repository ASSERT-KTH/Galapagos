// Function variant #1
// The functionality remains the same, but the organization of the variables and the syntax have been slightly changed.
void emit_ancillary_info (char const *program)
{
    char const *node = program;
    char const *url_program;
    char const *lc_messages;
    struct infomap 
    { 
        char const *program;
        char const *node; 
    } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call	 invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum",	 "sha2 utilities" },
        { nullptr, nullptr }
    };
    
    struct infomap const *map_prog = infomap;

    while (map_prog->program && ! STREQ(program, map_prog->program))
        map_prog++;
  
    if (map_prog->node)
        node = map_prog->node;

    printf(_("\n%s online	help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
  
    lc_messages = setlocale(LC_MESSAGES, nullptr);
  
    if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
        fputs(_("Report any	translation	bugs to "
       		"<https://translationproject.org/team/>\n"), stdout);
    }
  
    url_program = STREQ (program, "[") ? "test" : program;
  
    printf(_("Full	documentation <%s%s>\n"),
       PACKAGE_URL, url_program);
  
    printf(_("or available locally via: info '(coreutils) %s%s'\n"),
       node, node == program ? " invocation" : "");
} 
