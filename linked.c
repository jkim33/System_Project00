#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node { char artist[100]; char song[100]; struct song_node *next; };

void print_node(struct song_node* node) {
  printf("%s: %s\n",node -> artist, node -> song);
}

int compare(struct song_node* one, struct song_node* two){
  char a[200] = "hello";
  char b[200] = "hello";
  strcpy(a,one->artist);
  strcat(a,one->song);
  strcpy(b,two->artist);
  strcat(b,two->song);
  return strcmp(a,b);
  return 0;
}

int length(struct song_node* root) {
  int counter = 0;
  while (root) {
    counter++;
    root = root->next;
  }
  return counter;
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

struct song_node * insert_order(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  struct song_node* temp = n;
  struct song_node* prev;
  if (temp == NULL) {
    return insert_front(n,a,s);
  }
  if (temp && compare(new,temp) < 0) {
    return insert_front(n,a,s);
  }
  while (temp && compare(new,temp) > 0) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    prev->next = new;
    return n;
  }
  new->next = prev->next;
  prev->next = new;
  return n;
}

struct song_node * find_artist_song(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  struct song_node* temp = n;
  while(temp) {
    if (compare(new,temp) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return temp;
}

struct song_node * find_artist(struct song_node * n, char * a) {
  struct song_node* temp = n;
  while(temp) {
    if (strcmp(a, temp->artist) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return temp;
}

struct song_node * find_rand(struct song_node * n) {
  int counter = 0;
  struct song_node* temp = n;
  while(counter < length(n)) {
    if (strcmp(a, temp->artist) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return temp;

struct song_node * free_list(struct song_node * n) {
  while (n) {
    struct song_node * temp = n->next;
    free(n);
    n = temp;
  }
  return NULL;
}

int main() {
  srand(NULL);
  
  struct song_node * root = NULL;
  root = insert_order(root, "Queen","Bohemian Rhapsody");
  root = insert_order(root, "Radiohead","Creep");
  root = insert_order(root, "M83","Outro");
  root = insert_order(root, "A Man", "Man");
  root = insert_order(root, "M83", "Intro");
  root = insert_order(root, "Zep", "Heaven");
  print_list(root);
  
  printf("%d\n", compare(root, (root->next)));

  struct song_node * BR = (struct song_node *) malloc(sizeof(struct song_node));
  BR = find_artist_song(root, "Queen", "Bohemian Rhapsody");
  print_node(BR);

  struct song_node * M83 = (struct song_node *) malloc(sizeof(struct song_node));
  M83 = find_artist(root, "M83");
  print_node(M83);
  
  root = free_list(root);
  print_list(root);

}
