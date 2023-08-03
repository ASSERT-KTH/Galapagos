// Maintainers and copyright: Javier Cabrera-Arteaga <javierca@kth.se> and Javier Ron-Arteaga <javierro@kth.se>

#include "llvm/ADT/Twine.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include <system_error>
#include "llvm/Linker/Linker.h"
#include <llvm/IRReader/IRReader.h>
#include <future>
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"

#include "common/Common.h"
#include "linker/Linker.h"


using namespace llvm;
// using namespace linker;
// using namespace name;

unsigned DebugLevel;


static cl::opt<std::string> InputFilename(cl::Positional, cl::desc("<original bitcode>"), cl::init("-"));

static cl::opt<std::string> OutFileName(cl::Positional, cl::desc("<result bitcode>"));

static cl::opt<std::string> ReplacementFile("replacer",
                                     cl::desc("<variant bitcode file>"));


static cl::opt<std::string> FunctionNamesOriginal("function_name_in_input",
                                           cl::desc("<function name input>"));

static cl::opt<std::string> FunctionNamesReplacement("function_name_in_replacement",
                                           cl::desc("<function name input>"));


static cl::opt<unsigned, true> DebugLevelFlag(
        "mewe-merge-debug-level",
        cl::desc("Pass devbug level, 0 for none"),
        cl::location(DebugLevel),
        cl::init(0));

int main(int argc, const char **argv) {


    cl::ParseCommandLineOptions(argc, argv);

    LLVMContext context_original;
    SMDiagnostic error_original;

    errs() << "Parsing original bitcode " << InputFilename <<"\n";

    auto bitcode = parseIRFile(InputFilename, error_original, context_original);


    errs()  << "Parsing the replacement bitcode" << ReplacementFile << "\n";

    LLVMContext context_replacement;
    SMDiagnostic error_replacement;


    auto replacement_bitcode = parseIRFile(ReplacementFile, error_replacement, context_replacement);


    // TODO Now parse the replacement


    // TODO extract the replacement function
    // TODO throw error if the function does not exist


    // TODO Find the function by name in the original binary
    // TODO throw error if does not exist
    //
    // TODO Try to replace body as it is
    // TODO print message if it cannot
    //
    // TODO do some deterministic rules to fix it
    // - Rules:
    // 1 - Match number of parameters
    //  1.5 - Respect pointers to arrays as they ar defined in the go function
    //  1.6 - Replace then the calls to that function with the respective type
    // 2 - Remove unreachable by the default value of the returning type
    // 3 - Remove specific go calls e.g. panicMem
    // 4 - ...
    // TODO print message if it cannot



    // Print back the newly created binary

    errs() << "Creating linker " << error_original.getMessage() <<"\n";

    Linker linker(*bitcode);

    if(DebugLevel > 1) {

    }


    // std::error_code EC;
    // llvm::raw_fd_ostream OS(OutFileName, EC);
    //WriteBitcodeToFile(*bitcode, OS);
    // OS.flush();

    //errs() << "Added functions " << added << "\n";

    return 0;
}
