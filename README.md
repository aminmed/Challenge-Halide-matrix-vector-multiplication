# implementation of matrix vector multiplication using Halide lang  

//Descrition: 

The repository contains 'AXPY_C.c' which is a source code file to calculate the function AXPY from BLAS and 'AXPY_H.cpp' a code to calculate the same function using Halide language. 
The result for the two codes is a file .txt that contains the values of the output vector, we use the commande 'diff' to compare the two files, if the results are identicals, the both functions do the same.


//How to use it : 

Simply, you can execute the script 'script.sh' as fellow:
  sudo  ./script.sh <path_to_halide.h> <path_to_libHalide.so> 
You could also modify the script, just copy past the path to your Halide.h and libHalide into the variables PATH_TO_HEADER and PATH_TO_LIB.
The script will do all the work then for you (compiling, executing and comparing output files)

//installing.log : this is a file generated while i installed halide and LLVM from sources; it contains all what was printed in the terminal (i used the commande script installing.log)

Thanks ! 
