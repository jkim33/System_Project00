#include <stdlib.h>
#include <stdio.h>

struct song_node { char artist[100]; char song[100]; struct song_node *next; };

void print_list(struct song_node * n) {
  while(n) {
    printf("%s: %s | ",n -> artist, n -> song);
    n = n -> next;
  }
}

struct song_node * insert_front(struct node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  new -> artist = a;
  new -> song = s;
  new -> next = n;
  return new;
}

struct song_node * free_list(struct node * n) {
  while (n) {
    struct song_node temp = n -> next;
    free(n);
    n = temp;
  }
  return NULL;
}

