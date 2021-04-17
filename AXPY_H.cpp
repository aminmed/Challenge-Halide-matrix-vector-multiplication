#include "Halide.h"
#include <stdio.h>
using namespace Halide;

//this is a simple C function that calculates output = alpha*a+b; 
//this is a vector operation where a, b and output are vectors of floats
//len is integer represents the length of a vector

int main(int argc, char **argv) {

    //a and b here are the two vectors that we are using to test 
    int length = 10; 
    float a[10] = {10.11f,1.5f,0.02f,15.0f,18.05f,10.0f,15.5f,7.02f,2.0f,8.05f}; 
    float b[10] = {10.11f,1.5f,0.02f,15.0f,18.05f,10.0f,15.5f,7.02f,2.0f,8.05f}; 
    float c[10]; 
    float alpha = 1.5f; 
    //to use these two vectors, we create Buffers a_buf and b_buf as fellow :
    Buffer<float> a_buf(a);
    Buffer<float> b_buf(b);
    //declaring a function AXPY_H 
    Func AXPY_H; 
    Var x; 
    AXPY_H (x) = alpha * a_buf(x) + b_buf(x);
    //calculate the result using AXPY_H: 
    Buffer<float> c_buf = AXPY_H.realize(length);
    //writing the results to a file results_H.txt:
    FILE * f = fopen("results_H.txt","w"); 
    for(int i=0; i< length;i++)
        fprintf(f,"c[%d]=%.2f\n",i,c_buf(i)); 
    fclose(f); 

    return 0; 
}