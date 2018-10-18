#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"

struct song_node * array_index(struct song_node* array[], char * a));
void add_song(struct song_node* array[], char * a, char * s);
struct song_node * search_song(struct song_node* array[], char * a, char * s);
struct song_node * search_artist(struct song_node * array[], char * a);

#endif

