/*
Asad khan
CS 2211
Asn_5
matrix.c
*/

#include "matrix.h"
#include "datatype.h"
#include "bs_tree.h"
#include <stdio.h>

    

    // Matrix construction using bstree_ini();
    Matrix matrix_construction(void)
    {
        Matrix temp_matrix = (Matrix) bstree_ini();
        return temp_matrix;
    }
    // If location (index1, index2) is defined in Matrix m, then return 1.
    // Otherwise, return 0 
    unsigned char matrix_isin(Matrix m, Index index1, Index index2){
        
        // Allocate memory for temporary Key
        Key temp_key = key_gen(index1, index2);
        
        if (bstree_search(m, temp_key) != NULL)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

    // If location (index1, index2) is defined in Matrix m, then return a pointer to the associated
    // value. Otherwise, return NULL
    Value *matrix_get(Matrix m, Index index1, Index index2)
    {
        Key temp_key = key_gen(index1, index2);
        
        // Either returns a pointer(data) to associated value or NULL
        return bstree_search(m, temp_key);
    }
    
    // Assign value to Matrix m at location (index1, index2). 
    // If that location already has a value assigned, overwrite it
    void matrix_set(Matrix m, Index index1, Index index2, Value value){
        
        // Allocate memory for Key and Data
        Key temp_key = key_gen(index1, index2);
        Data temp_data = data_gen(value);
        
        // If NULL at location, insert value
        if (matrix_get(m, index1, index2) == NULL)
        {
            bstree_insert(m, temp_key, temp_data);
        }
        
        // If location already has value assigned
        // overwrite the value at the specified location
        // using the function'matrix_get' 
        else
        {
            
            *matrix_get(m, index1, index2) = *temp_data;
           
            
        }
    }
    //If location (index1, index2) is defined in Matrix m, then increase the associated value by
    //value. Otherwise, report error
    void matrix_inc(Matrix m, Index index1, Index index2, Value value){
        

        if (matrix_isin(m, index1, index2) == 1)
        {
            matrix_set(m, index1, index2, value);
        }
        else
        {
            printf("Error in increasing value, the value is not in Matrix m \n");
        }

    }
    
    //Print indices and values in the Matrix m with the function bstree_traversal();
    void matrix_list(Matrix m){
        
        bstree_traversal(m);
    }
    
    //Free allocated space with bstree free();
    void matrix_destruction(Matrix m){
        
        bstree_free(m);
    }
    


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    