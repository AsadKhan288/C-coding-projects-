/*
Asad khan
CS 2211
Asn_5
bs_tree.c
*/

#include "bs_tree.h"
#include "datatype.h"
#include <stdio.h>
#include <stdlib.h>


    // Allocate memory of type BStree_node*, set to 'NULL', and return a pointer to location where the memory was allocated
    BStree bstree_ini(void){
        
        BStree temp_bst;
        temp_bst = (BStree) malloc(sizeof(BStree_node*));
        *temp_bst = NULL;
        
        //Return pointer
        return temp_bst;
    
    }
    // Insert 'data' with 'key' in 'bst'. If key is in bst, then do nothing
    //
    void bstree_insert(BStree bst, Key key, Data data){
        
        //Use helper function to create pointer to bst node
        BStree_node *temp_node = new_node(key, data);
        
        // If tree is NULL, assign tree to the new node
        if (*bst == NULL)
        {
            *bst = temp_node;
            return;
        }
        
        // Intialize temporary root node for traversing
        BStree_node temp_root = **bst;
        
        // If 'less than 0' assign or traverse to right node if not NULL
        if (key_comp(temp_root.key, key) < 0)
        {
            if (temp_root.right == NULL)
            {
                
                (*bst)->right = temp_node;
            }
            else
            {
                bstree_insert(&temp_root.right, key, data);
            }
        }
        // If 'greater than 0' assign or traverse to left node if not NULL
        else if (key_comp(temp_root.key, key) > 0)
        {
            if (temp_root.left == NULL)
            {
                (*bst)->left = temp_node;
            }
            else
            {
                bstree_insert(&temp_root.left, key, data);
            }
        }
        
    }
    
    // Helper function for insertion to produce a pointer to a bst node 
    // from key and data
    BStree_node *new_node(Key key, Data data)
    {
        // memory allocation for new node
        BStree_node *temp_node = (BStree_node *) malloc(sizeof(BStree_node));
        
        //Assign values of key and data
        (*temp_node).key = key;
        (*temp_node).data = data;
        
        // Assign left and right node pointers to NULL
        (*temp_node).left = NULL;
        (*temp_node).right = NULL;
        
        //return new node 
        return temp_node;
        
    }
    
    // If the key is in bst, return the key’s associated data 
    // If the key is not in bst, return 'NULL'
    Data bstree_search(BStree bst, Key key){
        
        // If the tree is NULL, return NULL
        if (*bst == NULL)
        {
            return NULL;
        }
        
        // Initiazlize temporary root node for traversing
        BStree_node temp_root = **bst;
        
        // If key has been found, return the data
        if (key_comp(temp_root.key, key) == 0)
        {
            return (**bst).data;
        }
        
        // If value of key_comp is 'less than 0' and if right child is not NULL
        // return search with right child node
        // If the right child node is NULL, return NULL
        if (key_comp(temp_root.key, key) < 0) 
        {
            if (temp_root.right == NULL)
            {
                return NULL;
            }
            else
            {
                return bstree_search(&temp_root.right, key);
            }
        }
        // If value of key_comp is 'greater than 0' and if left child is not NULL
        // return search with left child node
        // If the left child node is NULL, return NULL
        else
        {
            if (temp_root.left == NULL)
            {
                return NULL;
            }
            else
            {
                return bstree_search(&temp_root.left, key);
            }
        }
        
    }
    
    // Function for the In order traversal of bst and to print each node's key and data
    void bstree_traversal(BStree bst){
        
        // If the tree is NULL, exit function
        if (*bst == NULL)
        {
            return;
        }
        // Initiazlize temporary root node for traversing
        BStree_node temp_root = **bst;
        
        //If left node not NULL, traverse left node
        if (temp_root.left != NULL)
        {
            
            bstree_traversal(&temp_root.left);
        }
        
        // Print Key and Data for node
        key_print(temp_root.key);
        data_print(temp_root.data);
        
        // If right node not NULL, traverse right node
        if (temp_root.right != NULL)
        {
            
            bstree_traversal(&temp_root.right);
        }
        
    }
    
    // Free all the dynamically allocated memory of the bst
    void bstree_free(BStree bst)
    {   
        //If bst is NULL, exit function
        if (*bst == NULL)
        {
            return;
        }
        
        bstree_free(&(*bst)->left);
        bstree_free(&(*bst)->right);
        free(*bst);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    