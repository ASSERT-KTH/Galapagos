Here are two changes to the program: 

Change 1: Altered the way translation bugs are reported. Instead of always referring users to translationproject.org, now the program instructs users to contact an email address directly – in this case, bugs@mysite.com.

Change 2: Instead of labeling all SHA hashes as "sha2 utilities" in the infomap, each now has its own unique description.

Filename: emit_ancillary_info_variant.cpp

void emit_ancillary_info(char const* program)
{
    struct infomap 
    { 
        char const* program; 
        char const* node; 
    } const infomap[] = 
    {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "SHA224 utility" },
        { "sha256sum", "SHA256 utility" },
        { "sha384sum", "SHA384 utility" },
        { "sha512sum", "SHA512 utility" },
        { nullptr, nullptr }
    };

    char const* node = program;
    infomap const* map_prog = infomap;

    while (map_prog->program && ! STREQ(program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const* lc_messages = setlocale(LC_MESSAGES, nullptr);

    if (lc_messages && STRNCMP_LIT(lc_messages, "en_"))
    {
        fputs(_("To report translation bugs, email "
                "bugs@mysite.com\n"), stdout);
    }

    char const* url_program = STREQ(program, "[") ? "test" : program;

    printf(_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf(_("Or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
}
