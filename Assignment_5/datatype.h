/*
Asad khan
CS 2211
Asn_5
datatype.h
*/

#ifndef keydata_H
#define keydata_H
    
    //Data type, pointer to int
    typedef int* Data;
    //Key type is a pair of strings
    typedef struct {char *skey1; char *skey2;} Key_struct;
    //Pointer to Key_struct
    typedef Key_struct* Key; 
    
    
    // Duplicate string pointed to by str with dynamic memory allocation.
    char * string_dup(char *str);
    
    // Generate a key with dynamic memory allocation.
    Key key_gen(char *skey1, char *skey2);
    
    // Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then
    // they determine the comparison result. If key1->skey1 and key2->skey1 are the same,
    // then key1->skey2 and key2->skey2 determine the comparison result.
    int key_comp(Key key1, Key key2);
    
    // Print a key
    void key_print(Key key);
    
    // Free memory allocated to a key
    void key_free(Key key);
    
    // Generate a data with dynamic memory allocation.
    Data data_gen(int idata);
    
    // Assign data with idata.
    void data_set(Data data, int idata);
    
    // Print a data
    void data_print(Data data);
    
    // Free memory allocated for data.
    void data_free(Data data);
    
#endif
    
    
    
    
    
    