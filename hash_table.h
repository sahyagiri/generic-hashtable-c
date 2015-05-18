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


#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#ifdef __cplusplus

extern "C"
{
#endif
   typedef int(*hash_key_comparison_pointer_type )(const void*const key1, const void* const key2 );
    struct hash_chain{
        void*value;
        struct hash_chain*next;
    };
    struct hash_entry{
        void* hash_key;
        struct hash_chain*hash_value_chain;// chain values
        struct hash_entry*next_hash_entry;
    };
    struct hash_table{
        struct hash_entry*start;
        struct hash_entry*current;
        hash_key_comparison_pointer_type compare_function;        
    };
    void put(struct hash_table*,void* key, void*value);
    struct hash_chain* get(struct hash_table*,void* key);
    struct hash_table* create(hash_key_comparison_pointer_type);
    void clear(struct hash_table*);
#ifdef __cplusplus
}
#endif

#endif
