/*
 *   Copyright 2015, Gireesan Namboothiri P. 
 *	
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */


#include <stdlib.h>
#include <stdio.h>
#include "hash_table.h"

struct hash_table* create(hash_key_comparison_pointer_type compare_function)
{
    struct hash_table*table=(struct hash_table*)malloc(sizeof(struct hash_table));
    table->start=(struct hash_entry*)malloc(sizeof(struct hash_entry));
    table->current=table->start;
    table->compare_function=compare_function;
    return table;
}
//linear search
struct hash_chain*get(struct hash_table*table,void* key){
    if(key==NULL) 
	return NULL;
    struct hash_entry*temp=table->start;
    while(temp!=NULL){
	if(temp->hash_key==NULL) // it is an error or the first entry with no value yet. Yet we will continue to next element
	{
		temp=temp->next_hash_entry;
		continue;
	}
        if(table->compare_function(temp->hash_key, key)==1)
        {
            return temp->hash_value_chain ;
        }
        temp=temp->next_hash_entry;
    }
    return NULL;
}
void put(struct hash_table* table,void* key, void* value){
    struct hash_chain*hash_value_chain=get(table,key);
    if(hash_value_chain==NULL)// we need to create an entry
    {
        struct hash_entry*current_entry=table->current;
        current_entry->hash_key=key;
        current_entry->hash_value_chain=(struct hash_chain*)malloc(sizeof(struct hash_chain));
        current_entry->hash_value_chain->value=value;
        current_entry->hash_value_chain->next=NULL;
        current_entry->next_hash_entry=(struct hash_entry*)malloc(sizeof(struct hash_entry));
        table->current=current_entry->next_hash_entry;
        table->current->next_hash_entry=NULL;
    }
    else{
        while(hash_value_chain->next!=NULL){
           hash_value_chain=hash_value_chain->next;
        }
        hash_value_chain->next=(struct hash_chain*)malloc(sizeof(struct hash_chain));
        hash_value_chain=hash_value_chain->next;
        hash_value_chain->value=value;
        hash_value_chain->next=NULL;        
    }
}
void clear(struct hash_table*table){
         struct hash_entry*temp_entry=table->start;
         while(temp_entry!=NULL){
            struct hash_entry*current=temp_entry;
            struct hash_chain*temp_list=temp_entry->hash_value_chain;
            while(temp_list!=NULL){
                 struct hash_chain*current_list=temp_list;
                 temp_list=temp_list->next;
                 free(current_list);
            }
            free(current);
            temp_entry=temp_entry->next_hash_entry;
         }
         table=NULL;
}
