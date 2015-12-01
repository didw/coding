#include <stdio.h>
#include <stdint.h>

#define N 200000	


int gohome (int64_t* parent, int64_t cnode, int64_t tnode){
	
	while ( cnode != 1 && cnode != tnode) {
//		fprintf(stderr, "->%lld", cnode);
		cnode = parent[cnode];
	}

	if( cnode == tnode ) {
//		fprintf(stderr, "-> success\n"); 
		return 1;
	}
	
//	fprintf(stderr, "-> fail\n");
	return 0;
}

int makequery(int64_t* parent, int64_t node1, int64_t node2){
	return gohome(parent, node1, node2) || gohome(parent, node2, node1);
}

void solveTest(FILE* in, FILE* out){

	int64_t parent[N];
	char buf[256];
	int64_t nlines,nqueries,i,p,c,node1,node2;

	if( !fgets(buf,256,in) ) {fprintf(stderr, "2: Cannot read\n"); }
	sscanf(buf,"%lld %lld", &nlines, &nqueries);

	fprintf(stderr, "New task\n");


	for(i=0; i<nlines-1; i++){
		if( !fgets(buf,256,in) ) {fprintf(stderr, "3: Cannot read file\n"); }
		sscanf(buf,"%lld %lld", &p, &c);
//		fprintf(stderr, "%lld -> %lld\n", p, c);
		parent[c] = p;
	}

//	fprintf(stderr, "New query\n");
	for(i=0; i<nqueries; i++){
		int res;
		if( !fgets(buf,256,in) ) {fprintf(stderr, "3: Cannot read file\n"); }
		sscanf(buf,"%lld %lld", &node1, &node2);

//		fprintf(stderr, "%lld -> %lld\n", node1, node2);

		res = makequery(parent, node1, node2);
		fprintf(out,"%d\n",res);
	}

}

int main(int argc, char* argv[]){
	FILE* f, *fout;
	char* file;
	char buf[256];
	int ntests, solution, i;

	fprintf(stderr, "Hello\n");
	if( argc != 2) { fprintf(stderr, "Specify input file\n"); return 0; }
	file = argv[1];
	fprintf(stderr, "Opening %s\n", file);
	f = fopen(file,"r");
	if( !f ) {fprintf(stderr, "Cannot open %s\n", file); }
	if( !fgets(buf,256,f) ) {fprintf(stderr, "1: Cannot read %s\n", file); }

	sscanf(buf,"%d", &ntests);
	fprintf(stderr, "Number of tests is %d\n", ntests);
	fout = fopen("res.out", "w");

	for(i = 0; i<ntests; i++) {
		solveTest(f, fout);
		//solution = solveTest(&test);
		//fprintf(fout, "%d\n", solution);
		//clearTask(&test);
	}
	
	return 0;
}

