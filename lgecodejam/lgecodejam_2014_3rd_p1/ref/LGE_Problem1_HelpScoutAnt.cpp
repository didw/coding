#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <list>

//A-small.in
//A-large.in
//inputset_small.txt
const char *inputFileName = "C:\\CodeJam_LGE\\Aug-2014\\Problem1\\A-small.in";
const char *outputFileName = "C:\\CodeJam_LGE\\Aug-2014\\Problem1\\outputset_small.txt";

//Node structure
typedef struct E_S_PATH_NODE
{
	int value;
	int depth;
	int parentNode;
	//struct E_S_PATH_NODE *nexNode;
	std::list<struct E_S_PATH_NODE *> *childList; 
	
} sNode;

sNode nodeArray[200000] = {NULL,};
void populateDepth(sNode *i_node,int i_nodes);

int main(int argc,char *argv[])
{
	FILE *fp = NULL,*fpOut =NULL;
	int testCases, nodes, queries, vertexStartNode, vertexEndNode, i;

	fp = fopen(inputFileName,"r");

	if(fp == NULL)
	{
		printf("Failed to open the file\n");
		return 0;
	}

	if(fp == NULL)
	{
		printf("Failed to open the file\n");
		return 0;
	}

	fpOut = fopen(outputFileName,"w");
	
	if(fpOut == NULL)
	{
		fclose(fp);

		printf("Failed to open the file\n");
		return 0;
	}

	//get first read width and then number of strings
	fscanf(fp,"%d",&testCases);

	//read all the vertices of tree
	while(testCases--)
	{
		fscanf(fp,"%d %d",&nodes,&queries);
		
		//Maintain the parent of a node
	//	nodeArray = (sNode **)malloc(sizeof(sNode *) * nodes);
		sNode *tmpNode = NULL, *newNode = NULL;

		//initialize the array
		for(i=0;i<nodes;i++)
		{
			nodeArray[i].value = i+1;

			if(i == 0)
				nodeArray[i].depth = 0;
			else
				nodeArray[i].depth = -1;

			nodeArray[i].parentNode = -1;
			nodeArray[i].childList = new std::list<struct E_S_PATH_NODE *>;
		}
		
		for(i=0;i<nodes-1;i++)
		{
			//get vertex
			fscanf(fp,"%d %d",&vertexStartNode,&vertexEndNode);
			//vertex End node in the child list of the startNode
			if(nodeArray[vertexStartNode-1].depth != -1)
				nodeArray[vertexEndNode-1].depth = nodeArray[vertexStartNode-1].depth+1;
			else
				nodeArray[vertexEndNode-1].depth  = -1;

			nodeArray[vertexEndNode-1].parentNode = vertexStartNode;

			nodeArray[vertexStartNode-1].childList->push_back(&nodeArray[vertexEndNode-1]);
		}

		tmpNode = &nodeArray[0];
	
		populateDepth(tmpNode,nodes);
		
		//scan values of queries
		for(i=0;i<queries;i++)
		{
			int nResult = 0;

			fscanf(fp,"%d %d",&vertexStartNode,&vertexEndNode);

			if(vertexStartNode == 1 || vertexEndNode == 1)
			{
				nResult =1;
			}
			else
			{
				if(nodeArray[vertexEndNode-1].depth == nodeArray[vertexStartNode-1].depth)
				{
					nResult = 0;
				}
				else
				{
					int startNode, depthDiff, endNode;

					//Search from the vertex to the difference of depth only
					if(nodeArray[vertexEndNode-1].depth > nodeArray[vertexStartNode-1].depth)
					{
						startNode = vertexEndNode;
						depthDiff = nodeArray[vertexEndNode-1].depth - nodeArray[vertexStartNode-1].depth;
						endNode = vertexStartNode;
					}
					else
					{
						startNode = vertexStartNode;
						depthDiff = nodeArray[vertexStartNode-1].depth - nodeArray[vertexEndNode-1].depth ;
						endNode = vertexEndNode;
					}
					
					tmpNode = &nodeArray[startNode-1];
					//Go reverse from child to parent and check if it is one of grand parent upto depth diff only
					while (depthDiff--)
					{
						tmpNode = &nodeArray[tmpNode->parentNode-1];
					}

					if(tmpNode->value == endNode)
						nResult = 1;
					else
						nResult = 0;
				}
			}

			//there will always be in path of vertexEndNode
			printf("Result No. [%d][%d]\n",i,nResult);
			fprintf(fpOut,"%d\n",nResult);
		}

		for(i=0;i<nodes;i++)
		{
			if(nodeArray[i].childList)
				delete (nodeArray[i].childList);
		}
	}

	fclose(fp);
	fclose(fpOut);

	return 0;
}

void populateDepth(sNode *i_node,int i_nodes)
{
	int *nodes = (int *)malloc(sizeof(int)*i_nodes);
	int top =0, treeNode, depth = 0;
	sNode *tmpNode = NULL;

	nodes[top++] = i_node->value;

	while(top != 0)
	{
		//pop top element
		treeNode = nodes[--top];
		
		//process node
//		tmpNode = *(nodeArray+treeNode-1);
		tmpNode = &nodeArray[treeNode-1];
		
		depth = tmpNode->depth + 1;
		//process it's child
		for (std::list<struct E_S_PATH_NODE *>::iterator it = tmpNode->childList->begin(); it != tmpNode->childList->end(); it++)
		{
			//push all the nodes in the stack
			nodes[top++] = (*it)->value;

			if((*it)->depth == -1)
				(*it)->depth= depth;
		}
	}
}
