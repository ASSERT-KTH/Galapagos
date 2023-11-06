Here is a program variant that changes the behaviour of the original function. This variant checks if the `program` passed as a parameter is part of the `infomap` array. If it is not part of the array, it changes its behaviour by not attempting to lookup the url_program.


void emit_ancillary_info(const char* program)
{
    struct infomap
    {
        const char* program;
        const char* node;
    } const infomap[] = {
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
        {nullptr, nullptr} };

    const char* node = program;
    const struct infomap* map_prog = infomap;
    bool found = false;

    while (map_prog->program && ! STREQ(program, map_prog->program)) {
        if (STREQ(map_prog->program, program)) {
            found = true;
            break;
        }
        map_prog++;
    }

    if (map_prog->node)
        node = map_prog->node;

    printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    const char* lc_messages = setlocale(LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT(lc_messages, "en_")) {
        fputs(_("Report any translation bugs to "
                "<https://translationproject.org/team/>\n"), stdout);
    }

    if (found) {
        const char* url_program = STREQ(program, "[") ? "test" : program;
        printf(_("Full documentation <%s%s>\n"),
               PACKAGE_URL, url_program);
        printf(_("or available locally via: info '(coreutils) %s%s'\n"),
               node, node == program ? " invocation" : "");
    }
}

Here, we have a boolean variable `found` which becomes `true` if the matching `program` variable is found in the `infomap[]` array. This `found` variable is used at the end to conditionally print certain log information if the `program` variable was originally in the `infomap[]` array.
Other than that, there are no huge changes that drastically affect the functionality or behavior. It is mainly to fine tune the amount of log information printed based on the validity of input.