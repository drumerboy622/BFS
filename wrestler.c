/************************************************************
 * Author: Matthew Solbrack
 * Date: 05/12/2019
 * Suject: HW 5. This algorithm uses the BFS to designate 
 * wrestlers as either a "good guy" (Babyfaces) or a 
 * "bad guy" (Heels). 
 ************************************************************/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct wrestlers
{
	char * name;
	int type;
	int visited;
	int changed;

}wrestlers;

int main(int argc, char **argv)
{
	struct wrestlers wrestler[100];
	struct wrestlers * matches[100];


	int i=0, j=1, v;
	char  arr[1000][15];
	FILE * textFile;

	
	//Get the file information first	
	if((textFile = fopen(argv[1], "r")))
	{
		while((fscanf(textFile, "%s", arr[i])) != EOF)
		{
			i++;
		}
	
		fclose(textFile);
	}


	// create struct for each wrestler 	
	int numWrestlers = atoi(arr[0]);

	for (j = 1; j <= numWrestlers; j++)
	{

		wrestler[j].name = arr[j];
		wrestler[j].type = 0;
		wrestler[j].visited = 0;
		wrestler[j].changed=0;
	
	}	

	// Put the fighter names into a readable array
	// and ind the number of edges for each    
	int numMatches = atoi(arr[j]);
	j++;
	v=0;
	int k, h;

	for (h = 0; h<numMatches; h++)
	{
		for(k = 1; k <= numWrestlers; k++)
		{

			

		 	if (strcmp(arr[j], wrestler[k].name) == 0)
			{		
				matches[v] = &wrestler[k];
				wrestler[k].visited = wrestler[k].visited + 1;
				k = numWrestlers+1;
				
			}

		}
		j++;
		v++;

		for(k = 1; k <= numWrestlers; k++)
                {



                        if (strcmp(arr[j], wrestler[k].name) == 0)
                        {
                                matches[v] = &wrestler[k];
				wrestler[k].visited = wrestler[k].visited + 1;
                                k = numWrestlers+1;
                        }

                }
		j++;
		v++;

	}

	/***************************************************************
		This Part of the program demonstrates the algorithm
	***************************************************************/

 

	// if the number of edges is odd change the type to BabyFaces
	for(k = 1; k <=numWrestlers; k++)
	{
		if (wrestler[k].visited % 2 == 0)
		{
			wrestler[k].type = 1;
		}

	}

	v=0;
	int victory = 0;
	// Check each match to make sure they are of different type, if they 
	// have not been visited and the types are the same, change one 
	// of the types and mark both wrestlers as changed
	for(k=0; k < numMatches; k++)
	{
		if(matches[v]->type == matches[v+1]->type)
		{
			if(matches[v+1]->changed == 0)
			{	
				if(matches[v+1]->type == 1)
					matches[v+1]->type = 0;
				else
					matches[v+1]->type = 1;
			}
			else if(matches[v]->changed == 0)
			{
                                if(matches[v]->type == 1)
                                        matches[v]->type = 0;
                                else
                                        matches[v]->type = 1;
                        }
			else 
				victory = 1;
		} 	
                matches[v]->changed = 1;
                matches[v+1]->changed = 1;

		v = v+2;
	}

	/************************************************************
 		Algorithm Finished
	************************************************************/	
	

	 	

	if (victory == 0)
	{

		//print the Babyfaces out	
		printf("Yes\nBabyfaces: ");
		for(k = 1; k <= numWrestlers; k++)
		{
			if ( wrestler[k].type == 1 )
			{
				printf("%s ", wrestler[k].name);
			}
		}
		printf("\n");


		// print the Heels out
	        printf("Heels: ");
	        for(k = 1; k <= numWrestlers; k++)
	        {
	                if ( wrestler[k].type == 0 )
	                {
	                        printf("%s ", wrestler[k].name);
	                }
	        }
	        printf("\n");
		
	

		return 0;

	}
	else
	{
		//print no
		printf("No\n");
	}
	
	return 0;
}
