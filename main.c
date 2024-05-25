/*
NAME: VISHAL L. JADHAV
DATE:
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
 */

#include"mp3.h"

int main(int argc,char *argv[])
{
    if(argc > 1)
    {
	if(!strcmp(argv[1],"--help"))
	{
	    printf("--------------------------------- HELP MENU -----------------------------------------\n\n");
	    printf("1. -v -> to view mp3 file contents\n");
	    printf("2. -e -> to edit mp3 file contents\n");
	    printf("        2.1. -t -> to edit song title\n");
	    printf("        2.2. -a -> to edit artist name\n");
	    printf("        2.3. -A -> to edit album name\n");
	    printf("        2.4. -y -> to edit year\n");
	    printf("        2.5. -m -> to edit content\n");
	    printf("        2.6. -c -> to edit comment\n");
	    printf("--------------------------------------------------------------------------------------\n\n");

	}
	else if(!strcmp(argv[1],"-v"))
	{
	    if(argv[2])
	    {
		if(validate_file(argv[2]) == SUCCESS)
		{
		    view(argv[2]);
		}
	    }
	    else
	    {
		printf("ERROR: PLEASE PASS FILENAME\n");
	    }

	}
	else if(!strcmp(argv[1],"-e"))
	{
	    if(validate_file(argv[4]) == SUCCESS)
	    {
		edit(argv[2],argv[3],argv[4]);
	    }
	}
	else
	{
	    printf("Please choose -v(view) or -e (edit) option\n");
	}
    }
    else
    {
	printf("----------------------------------------------------------------------------------\n\n");
	printf("ERROR: ./a.out  : INVALID ARGUMENTS\n");
	printf("USAGE :\n");
	printf("To view please pass like : ./a.out -v mp3filename\n");
	printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
	printf("To get help pass like : ./a.out --help\n\n");
	printf("----------------------------------------------------------------------------------\n\n");

    }
    return 0;
}
int validate_file(char *filename)
{
    FILE *fptr = fopen(filename,"r");
    
    if(fptr == NULL)
    {
	perror("Please pass .mp3 file\n");
	return FAILURE;
    }
    char id[4];
    fread(id,3,1,fptr);
    int version;
    fread(&version,2,1,fptr);

    if(strstr(filename,".mp3"))
    {
	if(!strcmp(id,"ID3") && (version == 3))
	{
	    return SUCCESS;
	}
    }
    return FAILURE;
}

