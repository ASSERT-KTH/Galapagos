import os

DIRNAME = os.path.abspath(os.path.dirname(__file__)) 

'''
    Abstract verifier class. Each verifier must implement the verify method.
'''
class Verifier:
    '''
        Receives two files and run the verification over them

        code1: file descriptor
        code2: file descriptor

        returns: True if the codes are equal, False otherwise
    '''
    def verify(code1, code2):
        raise NotImplementedError
    
class AliveVerifier(Verifier):

    '''
        Receives two files and run the alive verification over them. Files should be LLVM IR codes.
    '''
    def verify(self, code1, code2):
        raise NotImplementedError("Alive verifier is not implemented")
    
if __name__ == "__main__":
    v = AliveVerifier()
    code1 = open(os.path.join(DIRNAME, 'tests' ,'code1.ll'), 'r')
    code2 = open(os.path.join(DIRNAME, 'tests' ,'code2.ll'), 'r')

    v.verify(code1, code2)
