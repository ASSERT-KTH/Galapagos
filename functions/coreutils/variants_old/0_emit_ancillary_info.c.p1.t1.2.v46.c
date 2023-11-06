One minor way to variate the function is to remove the redundancy by having a separate variable to assign whether to display default term or program’s node. The target behavior of the function remains unchanged but the flow is modified a bit for cleaner and more maintainable code.

Here's the modified function:


void emit_ancillary_info(char const *program)
{
    struct infomap {
        char const *program;
        char const *node;
    } const infomap_list[] = {
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
        {nullptr, nullptr}};

    char const *node_name = program;
    for (struct infomap const *map_ptr = infomap_list; map_ptr->program; ++map_ptr)
    {
        if(STREQ(program, map_ptr->program))
        {
            node_name = map_ptr->node;
            break;
        }
    }

    printf("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT(lc_messages, "en_")) {
        fputs("Report any translation bugs to "
              "<https://translationproject.org/team/>\n", stdout);
    }
    char const *url_program = STREQ(program, "[") ? "test" : program;
    printf("Full documentation <%s%s>\n",
           PACKAGE_URL, url_program);
    printf("or available locally via: info '(coreutils) %s%s'\n",
           node_name, node_name == program ? " invocation" : "");
}



What changed:

1. Replaced the while loop with a for loop for better readability and flow control. The break statement is used instead of checking conditions in two places.

2. Renamed infomap to infomap_list & map_prog to map_ptr to elucidate meaning and simplify understanding.

3. Defined a distinct variable 'node_name' to assign whether to display default routing or node routing, thus reducing redundancy code.
