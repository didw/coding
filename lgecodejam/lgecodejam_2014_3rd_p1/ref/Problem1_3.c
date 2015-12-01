//OUTPUT will be redirected to output.txt
//main function, input file can be changed

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct Crossings {
	int key;
	struct Crossings *first_children;
	struct Crossings *next_sibling;
	struct Crossings *last_children;
	struct Crossings *first_parent;
	int numChildren;
}Crossings;

typedef struct TestCase{
	int numCrossings;
	int numQueries;
	Crossings *home;
}TestCase;


void addChildren(Crossings *node, Crossings *node_to_add)
{
	if(node->first_children == NULL)
	{
		node->first_children = node_to_add;
		node->last_children = node_to_add;
	}
	else
	{
		node->last_children->next_sibling=node_to_add;
		node->last_children = node_to_add;
	}
	node_to_add->first_parent=node;
	
	while(node != NULL)
	{
		node->numChildren=node->numChildren+node_to_add->numChildren+1;
		node=node->first_parent;
	}
}

/*void SearchInTree(Crossings *node,int key,int *key_found)
{
	if(node==NULL || *key_found)
		return;
	if(node->key == key)
	{
		*key_found=1;
		return;
	}

	node=node->first_children;
	while(node != NULL)
	{
		SearchInTree(node,key,key_found);
		node=node->next_sibling;
	}
	return;
}*/

int isNodesUnderOneSubTree(TestCase *test,Crossings *node1, Crossings *node2)
{
	int tot_child = 0;
	if(node2->numChildren == node1->numChildren)
		return 0;
	if(node2->numChildren > node1->numChildren)
	{
		// Swap Nodes
		Crossings *temp=node1;
		node1=node2;
		node2=temp;
	}
	
	while(tot_child <= node1->numChildren && node2 != NULL)
	{
		if(node2->key == node1->key)
			return 1;
		tot_child = node2->numChildren;
		node2 = node2->first_parent;
	}
	return 0;

}

void writeOutput(FILE *fp, int result,int testcaseNo,int queryNo)
{
	
	char resStr[10];
	
	ltoa(result,resStr,10);
	fputs(resStr,fp);
	fputs("\n",fp);
	printf("%ld.  %ld.  %ld\n",testcaseNo,queryNo,result);

}

void readInput(const char *in_filename, const char *out_file_name)
{
	FILE *in = NULL;
	FILE *output = NULL;
	int no_of_test = 0;
	char buffer[30];
	int loopidx = 0;
	TestCase *test=NULL;

	in = fopen(in_filename,"r");
	if(NULL == in){
		printf("\n File Open Error INPUT");
		return;
	}
	
	//OUTPUT FILE
	
	output = fopen(out_file_name,"w");
	if(NULL == output){
		printf("File open error OUTPUT");
		return;
	}

	fgets(buffer,20,in); //no of test cases
	no_of_test = atoi(buffer);


	test = (TestCase *)malloc(sizeof(TestCase));
	

	while(loopidx < no_of_test)
	{
		int idx = 0;
		Crossings **cross_array;
		fgets(buffer,20,in); //Read the Pair

		memset(test,0,sizeof(TestCase));
		test->numCrossings = atoi(strtok(buffer," "));
		test->numQueries = atoi(strtok(NULL," "));

		cross_array = (Crossings **) malloc(sizeof(Crossings *) * test->numCrossings);
		memset(cross_array,0,sizeof(Crossings *)*test->numCrossings);


		test->home = (Crossings *)malloc(sizeof(Crossings));
		memset(test->home,0,sizeof(Crossings));
		test->home->key = 1;
		

		cross_array[0] = test->home;

		while(idx < test->numCrossings-1)
		{
			int key_idx1=0;
			int key_idx2=0;
			
			fgets(buffer,20,in);
			key_idx1=atoi(strtok(buffer," "));
			key_idx2=atoi(strtok(NULL," "));


			if(cross_array[key_idx1-1] == NULL)
			{
				Crossings *node1 = (Crossings *)malloc(sizeof(Crossings));
				memset(node1,0,sizeof(Crossings));
				node1->key = key_idx1;
				cross_array[key_idx1-1]=node1;
			}
			if(cross_array[key_idx2-1] == NULL)
			{
				Crossings *node2 = (Crossings *)malloc(sizeof(Crossings));
				memset(node2,0,sizeof(Crossings));
				node2->key=key_idx2;
				node2->first_parent=NULL;
				cross_array[key_idx2-1]=node2;
			}
			addChildren(cross_array[key_idx1-1],cross_array[key_idx2-1]);
			idx++;
		}

		
		idx=0;
		while(idx < test->numQueries)
		{
			int *path_1=NULL;
			int path_cnt=0;
			int pos1=0;
			int pos2=0;
			int res=1;
			fgets(buffer,20,in);
		
			pos1 = atoi(strtok(buffer," "));
			pos2 = atoi(strtok(NULL," "));
			
			if((pos1 !=1 && pos2 != 1))				// 1 itself is a special crossing. Always return 1
			{
				res = isNodesUnderOneSubTree(test,cross_array[pos1-1],cross_array[pos2-1]);
			}
			writeOutput(output,res,loopidx,idx);
			idx++;
		}

		idx=0;
		while(idx < test->numCrossings)
		{
			free(cross_array[idx]);
			idx++;
		}
		free(cross_array);
		loopidx++;
	}
	free(test);
	printf("\n Finish Reading >>>>>>>\n ");

	fclose(in);
	fclose(output);

}



/*
OUTPUT WILL BE REDIRECTED TO output.txt
*/
int main(int argc, char* argv[])
{
	printf("Welcome CodeJam Problem 1\n\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments. Usage <Programme_1.exe> <Input File Path> <Output File Path>");
	}
	readInput(argv[1],argv[2]);
	getchar();

	return 0;
}
