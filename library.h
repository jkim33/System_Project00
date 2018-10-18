#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"

void add_song(struct song_node* array[], char* a, char* s);
void search_song(struct song_node* array[], char*a, char*s);

#endif

