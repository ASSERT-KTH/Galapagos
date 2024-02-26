// Maintainers and copyright: Javier Cabrera-Arteaga <javierca@kth.se> and Javier Ron-Arteaga <javierro@kth.se>

#include "llvm/ADT/Twine.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include <cstdlib>
#include <llvm/ADT/StringExtras.h>
#include <llvm/IR/Instructions.h>
#include <string>
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
#include "c/c.h"


using namespace common;
using namespace llvm;
// using namespace linker;
// using namespace name;

unsigned DebugLevel;

enum OperationMode {
    sld,
    cld,
    sln,
    cln
};

static cl::opt<std::string> InputFilename(cl::Positional, cl::desc("<original bitcode>"), cl::init("-"));

static cl::opt<std::string> OutFileName("output", cl::desc("<result bitcode>"));

static cl::list<std::string> ReplacementFiles(cl::Positional,
                                     cl::desc("<variant bitcode file>"));

static cl::opt<std::string> OutLLFile("outll", cl::desc("<path_ll>"));

static cl::opt<std::string> FunctionNamesOriginal("function_name_in_input",
                                           cl::desc("<function name input>"));

static cl::opt<std::string> FunctionNamesReplacement("function_name_in_replacement",
                                           cl::desc("<function name input>"));
static cl::opt<OperationMode> Mode(
    cl::desc("Specify the mode used to merge the functions:"), 
    cl::values(
        clEnumVal(sld, "same language diverse"),
        clEnumVal(cld, "cross language diverse"),
        clEnumVal(sln, "same language n-version"),
        clEnumVal(cln, "cross language n-version")
    ));

static cl::opt<unsigned, true> DebugLevelFlag(
        "debug-level",
        cl::desc("Pass devbug level, 0 for none"),
        cl::location(DebugLevel),
        cl::init(0));

int main(int argc, const char **argv) {


    cl::ParseCommandLineOptions(argc, argv);

    LLVMContext context_original;
    SMDiagnostic error_original;
    
    if(ReplacementFiles.size() < 1) {
        errs() << "Error: at least one variant file must be specified.\n";
        exit(-1);
    }


    if(ReplacementFiles.size() > 1 && (Mode == sld || Mode == cld)) {
        errs() << "Error: only one variant allowed for diverse execution mode.\n";
        exit(-1);
    }

    errs() << "Parsing original bitcode " << InputFilename <<"\n";

    auto bitcode = parseIRFile(InputFilename, error_original, context_original);

    errs() << "Parsing error original: " << error_original.getMessage() <<"\n";

    //Linker linker(*bitcode);

    // Find the function by name
    if(DebugLevel > 1) {
       errs() << "Finding " << FunctionNamesOriginal << " in the original\n";
    }

    auto original_function = getFunctionByName(*bitcode, FunctionNamesOriginal);

    std::vector<std::unique_ptr<llvm::Module>> replacement_bitcodes;

    for (auto file = ReplacementFiles.begin(); file != ReplacementFiles.end(); file++){
        LLVMContext context_replacement;
        SMDiagnostic error_replacement;
        replacement_bitcodes.push_back(parseIRFile(*file, error_replacement, context_original));
        errs() << "Parsing error variant: " << error_replacement.getMessage() << "\n";
    }


    std::vector<llvm::Function*> replacement_functions;
    
    for (auto bc = replacement_bitcodes.begin(); bc != replacement_bitcodes.end(); bc++){
        // Find the function by name
        if(DebugLevel > 1) {
            errs() << "Finding " << FunctionNamesReplacement << " in the replacement\n";
        }
        replacement_functions.push_back(getFunctionByName(**bc, FunctionNamesReplacement));
    }

    if(original_function && replacement_functions.size() == ReplacementFiles.size()) {
       if(DebugLevel > 1) {
          errs() << "All functions found. Making starting replacement \n";
       }

       // Replace the BasicBlocks of function 1 by Basic blocks of function2
       // Remove the original function

       llvm::Function* newfunction; 
       switch(Mode){
          case sld:
            newfunction = c::cloneFunction(*original_function, *replacement_functions[0]);
            break;
          case cld:
            newfunction = go::cloneFunction(*original_function, *replacement_functions[0]);
            go::patch(newfunction);
            break;
          case sln:
            newfunction = c::synthNVersion(*original_function, replacement_functions);
            break;
          case cln:
            errs() << "not implemented\n";
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
