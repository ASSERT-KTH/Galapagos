Here is the modified function which somewhat changes the behaviour of the original emit_ancillary_info function (although original functionality is kept too): 


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
    const struct infomap *default_infomap = &infomap[0]; // Default infomap
    struct infomap const *map_prog = infomap;

    while (map_prog->program) {
        if(STREQ (program, map_prog->program)) {
            break;
        }
        map_prog++;
        if(!map_prog->program) { // If end of Array is reached without a match.
            map_prog = default_infomap; // Assign default infomap
            break;
        }
    }

    if(map_prog->node) 
        node = map_prog->node;

    printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
        fputs ("Report any translation bugs to "
                "<https://translationproject.org/team/>\n", stdout);
    }
    const char *url_program = STREQ (program, "[") ? "test" : program;
    printf("Full documentation <%s%s>\n",
            PACKAGE_URL, url_program);
    printf ("or available locally via: info '(coreutils) %s%s'\n",
            node, node == program ? " invocation" : "");
}

In this modification, the function defaults to an available default infomap when there's no matching program in the array. Assuming that the purpose of the function is to output documentation details. In the event that the passed program name does not correspond with any of the `program` members in `infomap` structure, it defaults to the first mapping, as a means of guaranteeing that the function always produce documentation data — be it for the matched program or a default program.