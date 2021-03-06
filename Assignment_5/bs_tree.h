/*
Asad khan
CS 2211
Asn_5
bstree.h
*/

#ifndef BStree_node_H
#define BStree_node_H

    #include "datatype.h"
    
    typedef struct BStree_node
    {
        Key key;
        Data data;
        struct BStree_node *left, *right;
        
        
    } BStree_node;
   
    typedef BStree_node** BStree;
    
    // Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the allocatd memory
    BStree bstree_ini(void);
    
    // Insert 'data' with 'key' into 'bst'. If key is in bst, then do nothing
    //
    void bstree_insert(BStree bst, Key key, Data data);
    
    //Helper Function for insertion to create a pointer to a tree node from key and data
    BStree_node *new_node(Key key, Data data);
    
    // If key is in bst, return key’s associated data. If key is not in bst, return NULL.
    Data bstree_search(BStree bst, Key key);
    
    // In order traversal of bst and print each node's key and data
    void bstree_traversal(BStree bst);
    
    // Free all the dynamically allocated memory of bst
    void bstree_free(BStree bst);
    
    #endif
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    