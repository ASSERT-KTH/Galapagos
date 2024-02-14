#include <c/c.h>

extern unsigned DebugLevel;
namespace c {
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

    auto I = copyfrom.arg_begin();
    //TODO: this is a hack to remove the first arg from a go function.
    //move to the go file
    //I ++;


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
