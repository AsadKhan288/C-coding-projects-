/*
Asad khan
CS 2211
Asn_5
datatype.c

Implementing fuctions for type Data and type Key
*/

#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


    // Duplicate string pointed to by 'str' with dynamic memory allocation.
    char * string_dup(char *str){
        
        char *temp = (char *) malloc(strlen(str) + 1);
        temp = strcpy(temp, str);
        
        return temp;
        
    }
    
    // Generate a key with dynamic memory allocation
    Key key_gen(char *skey1, char *skey2){
        
        Key temp_key;
        temp_key = (Key_struct*)malloc(sizeof(Key_struct));
        
        (*temp_key).skey1 = string_dup(skey1);
        (*temp_key).skey2 = string_dup(skey2);
        
        return temp_key;
    }
    
    // Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then
    // they determine the comparison result. If key1->skey1 and key2->skey1 are the same,
    // then key1->skey2 and key2->skey2 determine the comparison result.
    int key_comp(Key key1, Key key2){
        
        // Initialize keys to be compared
        Key temp_1 = key1;
        Key temp_2 = key2; 
        
        // If both keys are NULL 
        // return 0
        if (temp_1 == NULL && temp_2 == NULL){
            
            return 0;
        }
        else if (temp_1 == NULL){
            return -1;
        }
        else if (temp_2 == NULL){
            return 1;
        }
        
        //If key1->skey1 and key2->skey1 are different, then
        // they determine the comparison result
        if (strcmp((*key1).skey1, (*key2).skey1) != 0)
        {
            return strcmp((*key1).skey1, (*key2).skey1);
        }
        //If not, key1->skey2 and key2->skey2 determine the comparison result
        else{
            return strcmp((*key1).skey2, (*key2).skey2);
        }
        
    }
    // Print a key
    void key_print(Key key){
        
        printf("%9s   %9s     ", (*key).skey1, (*key).skey2); 
    }
    
    // Free memory allocated to a key
    void key_free(Key key){
        
        free((*key).skey1);
        free((*key).skey2);
        free(key);
        
    }
    
    // Generate a 'data' with dynamic memory allocation.
    Data data_gen(int idata){
        
        Data temp_data;
        
        temp_data = (int *) malloc(sizeof(Data));
        *temp_data = idata;
   
        return temp_data;
    }
    
    // Assign data with idata.
    void data_set(Data data, int idata){
        
        Data temp_data = data_gen(idata);
        data = temp_data;
        
    }
    // Print a data
    void data_print(Data data){
        
        int temp_data = (*data);
        printf("%14d\n", temp_data);
    }
    
    // Free memory allocated for data.
    void data_free(Data data){
        
        free(data);
    }
    

    
    
    
    
    
    
    
    
    
    
