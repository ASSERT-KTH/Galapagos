
void emit_ancillary_info (const char *program)
{
    struct {
        const char *program;
        const char *node;
    } const informations[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { NULL, NULL }
    };

    const char *node = program;
    const typeof(informations) *instr_obj = informations;

    while (instr_obj->program && strcmp (program, instr_obj->program) != 0)
        ++instr_obj;

    if (instr_obj->node)
        node = instr_obj->node;

    printf ("\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

    const char *locale_messages = setlocale (LC_MESSAGES, NULL);
    if (locale_messages && strncasecmp(locale_messages, "en_", 3) != 0)
    {
        fputs ("Report any translation bugs to "
            "<https://translationproject.org/team/>\n", stdout);
    }
    
    const char *target_program = strcmp (program, "[") == 0? "test" : program;

    printf ("Full documentation <%s%s>\n",
        PACKAGE_URL, target_program);
    printf ("or available locally via: info '(coreutils) %s%s'\n",
        node, node == program ? " invocation" : "");
}

