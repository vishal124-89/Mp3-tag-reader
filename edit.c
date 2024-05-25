/*
NAME:
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include "mp3.h"

char keys[6][3] = {"-t","-a","-A","-y","-m","-c"};
extern char tag_frame[6][5];
extern char info[6][10];

int edit(char *key,char *new_data,char *filename)
{   
    
    FILE *filename_fptr = fopen(filename,"r+");

    if(filename_fptr == NULL)
    {
	printf("ERROR:%s file couldnt be opened\n",filename);
	return FAILURE;
    }

    int i = 0,size;
    char obtained_tag[4],temp;
    
    while(keys[i] != NULL)
    {
	if(!strcmp(keys[i],key))
	{
	    break;
	}
	i++;
    }

    char *tag_to_edit = tag_frame[i];
    
    fseek(filename_fptr,10,SEEK_SET);
    for(i=0;i<6;i++)
    {
	fread(obtained_tag,4,1,filename_fptr);
	fseek(filename_fptr,3,SEEK_CUR);
	fread(&size,4,1,filename_fptr);

	if(!strcmp(tag_to_edit,obtained_tag))
	{
	    if(encode_data(new_data,size,filename_fptr) == SUCCESS)
	    {
		printf("---------------------------------SELECTED EDIT DETAILS----------------------------\n\n");
		printf("INFO: DATA TO CHANGE: %s\n",info[i]);
		printf("%s    :   %s\n\n",info[i],new_data);
		printf("INFO: %s SUCCESSFULLY CHANGED.\n\n",info[i]);
		printf("-----------------------------------------------------------------------------------\n\n");
		return SUCCESS;
	    }
	   
	}
	else
	{
	    fseek(filename_fptr,size-1,SEEK_CUR);
	}
    }

}

int encode_data(char *new_data,int size,FILE *fptr)
{
    char buf[size];
    strcpy(buf,new_data);
    fwrite(buf,1,size-1,fptr);
    return SUCCESS;
}
