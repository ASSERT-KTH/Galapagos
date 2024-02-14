#include "go/go.h"

extern unsigned DebugLevel;

namespace go {
  void patch(llvm::Function* function) {
      // For GO only
      std::vector<CallInst*> toRemove;
      for(auto &BB: *function){
        for(auto &I: BB){
          if (CallInst* callInst = dyn_cast<CallInst>(&I)){
             if(DebugLevel > 2) {
               errs() << "Checking " << callInst->getCalledFunction()->getName() << "\n";
             }

             // TODO add more here
             if (callInst->getCalledFunction()->getName().contains("llvm.lifetime.")) {
                toRemove.push_back(callInst);
             }
             if (callInst->getCalledFunction()->getName().contains("runtime.")) {
                toRemove.push_back(callInst);
             }
          }
        }
      }
      for (auto callInst : toRemove) {
        callInst->eraseFromParent();
      }
  }


  llvm::Function* cloneFunction(llvm::Function& function, llvm::Function& copyfrom) {

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

    auto I = copyfrom.arg_begin(); I ++; //hack to replace first argument with "nest" attr

    auto I2 = NF->arg_begin();

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
