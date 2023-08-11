The following variant modifies the code to output information not just for the programs/environments specified in the original `infomap` also give a generic output for programs not in that list.


void emit_ancillary_info(char const* program) {
    struct infomap { char const* program; char const* node; } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };

    char const* node = "Generic program";
    struct infomap const* map_prog = infomap;

    while (map_prog->program && !STREQ(program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const* lc_messages = setlocale(LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
        fputs(_("Report any translation bugs to "
                "<https://translationproject.org/team/>\n"), stdout);
    }
    
    char const* url_program = STREQ(program, "[") ? "test" : program;
    printf(_("Full documentation <%s%s>\n"),
        PACKAGE_URL, url_program);
    printf(_("or available locally via: info '(coreutils) %s%s'\n"),
        node, 
        STREQ(node, "Generic program") ? "" : (node == program ? " invocation" : ""));
}

This version of the code works that if a program is passed to the function which is not in the infomap it sets the `node` value to `Generic program`. So, everybody (like end users or other parts of the program which call this function) knows that there is no specified information for that driven program execution, it's a generic program. But all other behaviors remain the same.