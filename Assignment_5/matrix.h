/*
Asad khan
CS 2211
Asn_5
matrix.h
*/

#ifndef matrix_H
#define matrix_H

    #include "bs_tree.h"
    typedef BStree Matrix;
    typedef char* Index;
    typedef int Value; 
    
    // Matrix construction using bstree ini();
    Matrix matrix_construction(void);
    
    // If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0 
    unsigned char matrix_isin(Matrix m, Index index1, Index index2);
    
    // If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
    // value. Otherwise, return NULL.
    Value *matrix_get(Matrix m, Index index1, Index index2);
    
    //Assign value to Matrix m at location (index1, index2). If that location already has value,
    //then overwrite
    void matrix_set(Matrix m, Index index1, Index index2, Value value);
    
    //If location (index1, index2) is defined in Matrix m, then increase the associated value by
    //value. Otherwise, report error
    void matrix_inc(Matrix m, Index index1, Index index2, Value value);
    
    //Print indices and values in the Matrix m (with bstree traversal())
    void matrix_list(Matrix m);
    
    //Free allocated space (with bstree free())
    void matrix_destruction(Matrix m);
    
#endif 
    
    
    
    
    
    
    
    
    
    
    