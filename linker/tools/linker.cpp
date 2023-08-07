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
#include <llvm/ADT/StringExtras.h>
#include <llvm/IR/Instructions.h>
#include <system_error>
#include "llvm/Linker/Linker.h"
#include <llvm/IRReader/IRReader.h>
#include <future>
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Transforms/Utils/ValueMapper.h"
#include "llvm/Transforms/Utils/Cloning.h"

#include "common/Common.h"
#include "linker/Linker.h"
#include "go/go.h"


using namespace common;
using namespace llvm;
using namespace go;
// using namespace linker;
// using namespace name;

unsigned DebugLevel;


static cl::opt<std::string> InputFilename(cl::Positional, cl::desc("<original bitcode>"), cl::init("-"));

static cl::opt<std::string> OutFileName("output", cl::desc("<result bitcode>"));

static cl::opt<std::string> ReplacementFile(cl::Positional,
                                     cl::desc("<variant bitcode file>"));

static cl::opt<std::string> OutLLFile("outll", cl::desc("<path_ll>"));

static cl::opt<std::string> FunctionNamesOriginal("function_name_in_input",
                                           cl::desc("<function name input>"));

static cl::opt<std::string> FunctionNamesReplacement("function_name_in_replacement",
                                           cl::desc("<function name input>"));
static cl::opt<uint> Language("lang",
    cl::desc("Specify the patch used merge the functions. 0 for none, 1 for Go"),
    cl::init(1));

static cl::opt<unsigned, true> DebugLevelFlag(
        "debug-level",
        cl::desc("Pass devbug level, 0 for none"),
        cl::location(DebugLevel),
        cl::init(0));

int main(int argc, const char **argv) {


    cl::ParseCommandLineOptions(argc, argv);

    LLVMContext context_original;
    SMDiagnostic error_original;

    errs() << "Parsing original bitcode " << InputFilename <<"\n";

    auto bitcode = parseIRFile(InputFilename, error_original, context_original);

    errs() << "Parsing error original: " << error_original.getMessage() <<"\n";

    //Linker linker(*bitcode);

    // Find the function by name
    if(DebugLevel > 1) {
       errs() << "Finding " << FunctionNamesOriginal << " in the original\n";
    }

    auto original_function = getFunctionByName(*bitcode, FunctionNamesOriginal);


    errs()  << "Parsing the replacement bitcode " << ReplacementFile << "\n";

    LLVMContext context_replacement;
    SMDiagnostic error_replacement;


    auto replacement_bitcode = parseIRFile(ReplacementFile, error_replacement, context_original);

    errs() << "Parsing error variant: " << error_replacement.getMessage() << "\n";

    //Linker linker2(*replacement_bitcode);


    // Find the function by name

    if(DebugLevel > 1) {
       errs() << "Finding " << FunctionNamesReplacement << " in the replacement\n";
    }

    auto replacement_function = getFunctionByName(*replacement_bitcode, FunctionNamesReplacement);



    if(original_function && replacement_function) {
       if(DebugLevel > 1) {
          errs() << "Both functions found. Making starting replacement \n";
       }

       // Replace the BasicBlocks of function 1 by Basic blocks of function2
       // Remove the original function

       auto newfunction = cloneFunction(*bitcode, *original_function, *replacement_function);

       if(DebugLevel > 2){
         errs() << "Basic blocks removed from original function \n";
       }
       // replacement_function->splice(original_function->begin(), replacement_function);
       // Creates a new one with the same signature and attributes
       // Iterates though the basic blocks of the replacement function,
       //

       switch(Language){
          case 1:
            go::patch(newfunction);
            break;
          default:
            break;
       }

       std::error_code EC;
       llvm::raw_fd_ostream OS(OutFileName, EC);
       // WriteBitcodeToFile(*bitcode, OS);
       OS << *bitcode;
       OS.flush();

    } else {
        errs() << "One of the functions could not be found. Ensure you passed their correct names\n";
        return 1;
    }

    return 0;
}
