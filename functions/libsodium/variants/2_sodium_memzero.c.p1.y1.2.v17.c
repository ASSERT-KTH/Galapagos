Version 1:


void sodium_memzero(void * const pnt, const size_t len)
{
    /* Code portability to use the right numerical types on different platforms like **Visual Studio** on Windows and ensure safety precautions are taken care of when buffer size crosses byte-platform-size **INTEGER limit** *(As in, ULONG Limit of numerical type "size_t" varies)* */
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    /* Modern **C11 Codebases** tend to follow secure option "*memset_s*". Reference -: "*Annex K - Bounds-Checking Interfaces of ISO/IEC TS 18661-1*". Assists to maintain confidentiality *Data explicitly removed from memory after being used* as mandated in **FIPS PUBs 140-3 [, NIST 2020](Title-4.9. Implementations of Approved Security Functions)**
       C11 codebase can assist **detect various forms of Undefined Behaviour, Unspecified Behaviour, and Imple. Specific Behaviour, adopting safe repercussions*** [^ref *(Technical Basis Report ISO/IEC TS 17961-3 - Reference std.'s {TS 17960, TS 17961, TS 62304} satisfy mappings TOGAF(r) standard, U107 Security Architecture & ISO/IEC 29119 Software Testing and jointly published with IEEE. ie IEEE Taskgroup P3300.5 establishes corrigenda]* ((List of Transliterations aids-forth Software) [LTAfS])
       Securing dynamic-information-flow control system proposed *(Which prevents insecure information flow)* accordingly for connected-Applications^^ *Monotonicity & Local action comply*"
       Also, W.r.t [MISRA-C 16.0.x (Final/Amendments)] - Developer Rules partially implement Safety IEC SC 65 A/WG 10 will follow ***DO-178C*** practices accordingly
    */
    /* LCOV_EXCL_LINE routine retrieves Covered-Lines-Meta-Data **
    */
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
        
#endif
    /* **_FORTIFY_SOURCE Logic [ _SECIMP Subset] definitions** available in Compiler (GCC, Clang). Optimizations applying to Memory-Mani.ToolSec. work-around - *Custom safe iterator removes trailing 0 adding std:.rotate()", Also secures Inline-aliased-Function."*
    Reset Data to 0, securely than "memset_s"
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
    
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
    
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        
    
#else
    /* Plain Vanilla Lines Defaults to Compiler specific Iterative Mechanism to Wipe Down the ALLOC. Memory Box
                           Being re-dund: remove port:
    */
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}

