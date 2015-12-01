#include <vector>
#include <iostream>
using namespace std;

FILE *infile, *outfile;
int first, second;
int remain_cross, start_cross;
int result;
int cross_num, question_num;

int main(void) {

	infile = fopen("A-large.in", "r");
	outfile = fopen("result.out", "w");

	int cases;
	fscanf(infile, "%d", &cases);

	while (cases > 0) {

		fscanf(infile, "%d %d", &cross_num, &question_num);
		int* array;

		array = new int[cross_num];
		
		int temp = cross_num;
		array[0] = -1;

		while (temp > 1) {
			int start, end;
			fscanf(infile, "%d %d", &start, &end);
			start--;
			end--;
			array[end] = start;
			temp--;
		}

		while (question_num > 0) {
			
			fscanf(infile, "%d %d", &first, &second);
			first--;
			second--;
			result = 0;
			
			for (int i = 0; i < 2; i++) {
				int searching;

				if (i == 0) {
					searching = first;
					remain_cross = second;
				} else {
					searching = second;
					remain_cross = first;
				}
				while (array[searching] >= 0) {
					if (array[searching] == remain_cross) {
						result = 1;
						break;
					}
					searching = array[searching];
				}
				if (result == 1) {
					break;
				}
			}
			
			fprintf(outfile, "%d\n", result);
			question_num--;
		}
		cases--;
		delete array;
	}
	
	if (infile != NULL) {
		fclose(infile);
		fclose(outfile);
	}
	return 0;
}


