#include <stdlib.h>
#include <stdio.h>

//this is a simple C function that calculates output = alpha*a+b; 
//this is a vector operation where a, b and output are vectors of floats
//len is integer represents the length of a vector
void AXPY_C(float alpha, float* a,float* b,float* output,int len){
    for(int i=0; i<len; i++) 
        output[i] = alpha * a[i] + b[i]; 
} 

int main(int argc, char **argv) {

    //a and b here are the two vectors that we are using to test 
    int length = 10; 
    float a[10] = {10.11f,1.5f,0.02f,15.0f,18.05f,10.0f,15.5f,7.02f,2.0f,8.05f}; //first vector
    float b[10] = {10.11f,1.5f,0.02f,15.0f,18.05f,10.0f,15.5f,7.02f,2.0f,8.05f}; //second vector
    float c[10]; //the vector where we put the result
    float alpha = 1.5f; 

    AXPY_C(alpha,a,b,c,length); 
    //writing the results to a file results_C.txt:
    FILE * f = fopen("results_C.txt","w"); 
    for(int i=0; i< length;i++)
        fprintf(f,"c[%d]=%.2f\n",i,c[i]); 
    fclose(f); 

    return 0; 
}