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

#include <stdio.h>
#include "hash_table.h"
int integer_key_comparison(const void*const key1, const void* const key2){
	// There is no harm in checking a null 
	if(key1==NULL)
		return 0;
	if(key2==NULL) 
		return 0;
	int*key_a=(int*) key1;
	int*key_b=(int*) key2;
	if(*key_a==*key_b) // compare the values 
		return 1;
	return 0;
}
int main(){
    hash_key_comparison_pointer_type compare_integer=integer_key_comparison;
    struct hash_table* table=create(compare_integer);
    int keys[]={1,2,3,4,3};
    int values[]={12,43,442,123,642};
    const int SIZE=5;
    int index;
    for(index=0;index<SIZE;index++){
        put(table,&keys[index],&values[index]);
    }
    for(index=0;index<SIZE;index++){
        struct hash_chain*entries=get(table, &keys[index]);
        while(entries!=NULL){
            int *value_stored=entries->value;
            printf("keys %d\t value %d\n",keys[index],*value_stored);
            entries=entries->next;
        }
    }
    clear(table);
    return 0;
}
