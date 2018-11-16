#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(length);
  for(int i=0; i < length; i++){
    int isthere = hash_table_retrieve(ht, limit - weights[i]);
    if(isthere != -1){
      Answer *toReturn =malloc(sizeof(toReturn));
      toReturn->index_1 = i;
      toReturn->index_2 = isthere;
      destroy_hash_table(ht);
      return toReturn;
    }
        hash_table_insert(ht,weights[i],i);
  }
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}