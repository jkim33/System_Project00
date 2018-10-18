#include "library.h"

struct song_node * array_index(struct song_node* array[], char * a){
  int index = a[0] - "a";
  struct song_node * start = array[index];
}

void add_song(struct song_node* array[], char * a, char * s){
  struct song_node * start = array_index(array, a);
  insert_order(start, a, s);
}

struct song_node * search_song(struct song_node* array[], char * a, char * s){
  struct song_node * start = array_index(array, a);
  struct song_node * found = find_artist_song(start, a, s);
  return found;
}

struct song_node * search_artist(struct song_node * array[], char * a){
  struct song_node * start = array_index(array, a);
  struct song_node * found = find_artist(start, a);
  return found;
}
