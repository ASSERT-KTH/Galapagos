Variant 1:

In this variant, I have reordered the string compare checks, first checking if the program is "[" and use "test", later cycles over other info mapping.

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

    char const *node = program,
               *url_program = program;

    // first, handle "[" -> "test"
    if(STREQ(program, "["))
       url_program = "test";

    // then, check other program mappings
    struct infomap const *map_prog = infomap;
    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;
     
    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);
    
    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        fputs (_("Report any translation bugs to <https://translationproject.org/team/>\n"), stdout);
    
    printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


Variant 2:

In this variant, during iteration over the array infomap, it checks each time if it has found the match and if so, will break out of the loop. Thus, avoiding unnecessary iterations.

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
    struct infomap const *map_prog = nullptr;
    
    for (int i=0; infomap[i].program != nullptr; ++i) {
        if(STREQ(program, infomap[i].program)){
            map_prog = &infomap[i];
            break;
        }
    }

    if(map_prog != nullptr){
       if (map_prog->node)
           node = map_prog->node;
    }

   
    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
       fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    
    
    char const *url_program = STREQ (program, "[") ? "test" : program; 
    printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}
