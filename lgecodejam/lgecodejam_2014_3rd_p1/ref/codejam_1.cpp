#include <stdio.h>
#include <stdlib.h>

typedef struct NodePlace{
	int data;
	int parent;
}Place;

FILE *fp;

int main(){

	int caseCount;
	int nodeCount;
	int questionCount;

	Place *Nodes;

	fp = fopen("input.txt", "r+");

	fscanf(fp, "%d", &caseCount);

	for(int i = 0; i < caseCount; i++){
		int firstPlace, secondPlace;
		fscanf(fp, "%d%d", &nodeCount, &questionCount);

		Nodes = (Place *)malloc(sizeof(Place) * nodeCount);
		for(int j = 0; j < nodeCount; j++){
			Nodes[j].data = j;
		}

		for(int j = 0; j < nodeCount-1; j++){
			int parent, child;
			fscanf(fp, "%d%d", &parent, &child);
			Nodes[child-1].parent = parent-1;
		}
		Nodes[0].parent = -1;

		for(int j = 0; j < questionCount; j++){
			Place *startPlace;
			int targetPlace = -1;
			bool isParent = false;

			fscanf(fp, "%d%d", &firstPlace, &secondPlace);
			if(firstPlace == 1 || secondPlace == 1)
				isParent = true;
			startPlace = &Nodes[secondPlace-1];
			targetPlace = firstPlace-1;
			while(startPlace->parent != -1){
				if(startPlace->data == targetPlace)
					isParent = true;
				startPlace = &Nodes[startPlace->parent];
			}
			startPlace = &Nodes[firstPlace-1];
			targetPlace = secondPlace-1;
			while(startPlace->parent != -1){
				if(startPlace->data == targetPlace)
					isParent = true;
				startPlace = &Nodes[startPlace->parent];
			}
			printf("%d\n", isParent);
		}
		free(Nodes);
	}

	fclose(fp);

	return 0;
}
