#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct song_node { char artist[100]; char song[100]; struct song_node *next; };

int compare(struct song_node* one, struct song_node* two){
  char a[200];
  char b[200];
  strcpy(a,one->artist);
  strcat(a,one->song);
  strcpy(b,two->artist);
  strcat(b,two->song);
  char * aa = a;
  char * bb = b;
  return strcmp(aa,bb);
}

void print_list(struct song_node * n) {
  printf("| ");
  while(n) {
    printf("%s: %s | ",n -> artist, n -> song);
    n = n -> next;
  }
  printf("\n");
}

struct song_node * insert_front(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  new -> next = n;
  return new;
}

struct song_node * free_list(struct song_node * n) {
  while (n) {
    struct song_node * temp = n->next;
    free(n);
    n = temp;
  }
  return NULL;
}

int main() {
  struct song_node * root = NULL;
  root = insert_front(root, "Queen","Bohemian Rhapsody");
  root = insert_front(root, "Radiohead","Creep");
  root = insert_front(root, "m83","Outro");

  print_list(root);

  root = free_list(root);

  print_list(root);

  printf("%d", compare(root, root->next));
}
