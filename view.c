/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include"mp3.h"

char info[6][10] = {"TITLE","ARTIST","ALBUM","YEAR","MUSIC","LANGUAGE"};
char tag_frame[6][5] = {"TIT2","TPE1","TALB","TYER","TCON","COMM"};

int view(char *filename)
{
    FILE *fptr = fopen(filename,"r");

    fseek(fptr,10,SEEK_SET);

    char tag[4],temp;
    int j=0,last,rev=0,size;
    char *ptr = (char *)&size;
   
    printf("\n");
   
    printf("----------------SELECTED VIEW DETAILS-----------------\n");
    printf("------------------------------------------------------\n");
    printf("        MP3 TAG READER AND EDITOR FOR ID3v3           \n");
    printf("------------------------------------------------------\n");

    for(j=0;j<6;j++)
    {
	fread(tag,4,1,fptr);
	if(!strcmp(tag,tag_frame[j]))
	{
	    fread(&size,4,1,fptr);

	    for(int i=0;i<(sizeof(int)/2);i++)
	    {
		temp = ptr[i];
		ptr[i] = ptr[sizeof(int)-i-1];
		ptr[sizeof(int)-i-1] = temp;
	    }

	    char *data = malloc(size*sizeof(char));

	    fseek(fptr,3,SEEK_CUR);
	    fread(data,size-1,1,fptr);
	    data[size-1] = '\0';
	    printf("%-20s  :",info[j]);
	    printf("    %-20s\n",data);

	    free(data);
	}
    }
    printf("\n");
    printf("----------------DETAILS DISPLAYED SUCCESSFULLY-------------\n");
    return SUCCESS;
}

