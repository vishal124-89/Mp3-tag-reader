#ifndef MP3_H
#define MP3_H

#define SUCCESS 1
#define FAILURE 0

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Validate header */

int validate_file(char *filename);

/* To view mp3 file details */

int view(char *filename);

/* To edit the contents of mp3 file*/

int edit(char *key,char *new_data,char *filename);

/* To write data into file */

int encode_data(char *new_data,int size,FILE *fptr);

#endif
