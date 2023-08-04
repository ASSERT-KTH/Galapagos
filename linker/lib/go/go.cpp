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
}
