#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"

int main() {
  srand(time(NULL));
  
  struct song_node * root = NULL;
  root = insert_order(root, "Queen","Bohemian Rhapsody");
  root = insert_order(root, "Radiohead","Creep");
  root = insert_order(root, "M83","Outro");
  root = insert_order(root, "AC/DC", "Highway to Hell");
  root = insert_order(root, "M83", "Intro");
  root = insert_order(root, "Radiohead", "Karma Police");
  print_list(root);

  printf("Length: %d\n", length(root));
  
  printf("Comparing Highway to Hell and Intro: %d\n", compare(root, (root->next)));

  struct song_node * BR = (struct song_node *) malloc(sizeof(struct song_node));
  BR = find_artist_song(root, "Queen", "Bohemian Rhapsody");
  print_node(BR);

  struct song_node * M83 = (struct song_node *) malloc(sizeof(struct song_node));
  M83 = find_artist(root, "M83");
  print_node(M83);;

  struct song_node * RAND = (struct song_node *) malloc(sizeof(struct song_node));
  RAND = find_rand(root);
  print_node(RAND);

  root = remove_node(root, "Queen", "Bohemian Rhapsody");
  root = remove_node(root, "AC/DC", "Highway to Hell");
  root = remove_node(root, "Radiohead", "Karma Police");
  root = remove_node(root, "Hi", "Hi");
  print_list(root);
  
  root = free_list(root);
  print_list(root);

}
