#include "common/Common.h"



extern unsigned DebugLevel;

namespace common {
  // Extract function by name
  // Receives the bitcode structure and the function name
  // Returns a pointer to the function extracted
  // Returns null if the function is not found
  //
  llvm::Function* getFunctionByName(llvm::Module& mod, llvm::StringRef name) {
     // Iterate over all functions of mod
     for(auto &F: mod) {
       if(DebugLevel > 2) {
          errs() << "\t" << F.getName() << "\n";
       }

       // Compare the names
       if(F.getName() == name && !F.isDeclaration()) {
          if(DebugLevel > 2) {
            errs() << "\tFunction found !\n";
          }
          if(DebugLevel > 3) {
            errs() << F << "\n";
          }
          return &F;
       }
     }

     // Return null ptr
     return NULL;
  }

  // Returns a function with and empty body with the same signature
  // as the passed argument
  llvm::Function* cloneFunction(llvm::Module& inmodule,  llvm::Function& function, llvm::Function& copyfrom) {

    FunctionType *FTy = function.getFunctionType();
    std::vector<Type *> Params(FTy->param_begin(), FTy->param_end());
    FunctionType *NFTy = FunctionType::get(FTy->getReturnType(), Params, false);
    unsigned NumArgs = Params.size();

    // Create the new function body and insert it into the module...
    Function *NF = Function::Create(NFTy, function.getLinkage(), function.getAddressSpace());
    NF->copyAttributesFrom(&function);
    NF->setComdat(function.getComdat());
    function.getParent()->getFunctionList().insert(function.getIterator(), NF);
    NF->takeName(&function);


    NF->splice(NF->begin(), &copyfrom);

    auto I = copyfrom.arg_begin();
    I ++;

    auto I2 = NF->arg_begin();
    //I ++;

    // Setting the name of the arguments
   for (Function::arg_iterator E = copyfrom.arg_end();
       I != E; ++I, ++I2) {
       errs() << *I2 << "\n";
       errs() << *I << "\n";
       // Move the name and users over to the new version.
       I2->takeName(&*I);
       I->replaceAllUsesWith(&*I2);

   }
    // Replace calls by this one

    // TODO replace also the calls to NF by NF itself

    // Fix up any BlockAddresses that refer to the function.
    function.replaceAllUsesWith(ConstantExpr::getBitCast(NF, function.getType()));
    // Finally, nuke the old function.
    function.eraseFromParent();


    if(DebugLevel > 2){
      errs() << "New function \n";
      errs() <<  *NF << "\n";
    }
    return NF;
  }
}

