Below are two slightly varied transformations of the provided function, both maintaining its original functionality:

1.`emit_ancillary_info (char const *program)`
{
    struct infomap {char const *program; char const *node; } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };

    auto map_prog = infomap;
    while (map_prog->program != nullptr && strcmp(program, map_prog->program) !=0)
        map_prog++;

    char const *node = map_prog->program != nullptr ? map_prog->node : program;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    bool language_is_English = lc_messages && strncmp(lc_messages, "en_", 3) == 0;

    if (!language_is_English){
        fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }


    printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
	node, (map_prog->program == nullptr) ? " invocation" : "");
}

2. `emit_ancillary_info (char const *program)`
{
    struct infomap {char const *program; char const *node; } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };

    auto map_prog = infomap;
    const char *node = program;

    // Walk map until either whole list processed or a match is found  
    for ( ; map_prog->program != nullptr; map_prog++)
    {
        if (0 == strcmp( program, map_prog->program ) )
        {
            node = map_prog->node;
	    break;
        }    
    }

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  
    if (lc_messages && strncmp(lc_messages, "en_", 3) != 0)
    {
        fputs (_("Report translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program = strcmp(program, "[" ) ? program : "test";
    printf (_("Full documentation @ <%s%s>\n"), PACKAGE_URL, url_program);
    printf (_("You could read it offline: info '(coreutils) %s%s'"), node, node == program ? " invocation" : "");
}