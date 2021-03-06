#include <stdlib.h>
#include <stdio.h>
#include "PropertyParser.h"
#include "RayCaster.h"

void cleanUpObjectList(OBJECT_LIST_STR * _objectList);
OBJECT_LIST_STR *getProperties(char *_filename);

int main(int argc, char** argv) 
{

	if(argc != 5)
	{
		fprintf(stderr, "Error: There must be 5 arguments, %d input. please try again \n", argc);
		return 1;
	}

	if(atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0)
	{
		fprintf(stderr, "Error: Width and Height cannot be equal to or less than 0. \n");
		return 1;
	}
    
    printf("Running parser with file %s\n",argv[3]);
    OBJECT_LIST_STR  *list = getProperties(argv[3]);

    //print the properties to try to get them
    printf("%d is the number of objects \n", list[0].numObjects);


    render(atoi(argv[1]), atoi(argv[2]), list, argv[4]);

    
    
    // Here you can do soemthing with  the structure
    
    // Clean out the memory 
    cleanUpObjectList(list);

    return 0;
}

