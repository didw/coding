#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include <time.h>

#pragma warning(disable: 4996)


typedef struct _MPOINT{
	int prev_val;
	int depth;
	int is_not_endpoint;
} MPOINT;

void read_a_case(FILE *TC, FILE *file_out);
void finddepth(int num);

# define result_print printf
# define logprint 
MPOINT mPint[200010];
int temp_num[210000];
void main()
{
	FILE *fp_tc,*fp_result;
	int nCase,i;

	fp_tc = fopen("d:\\A-large.in", "r");
	fp_result = fopen("d:\\result.txt", "w");
	fscanf(fp_tc, "%d\n", &nCase);
	logprint("case count=%d\n", nCase);
	for (i = 0; i < nCase; i++)
	{
		read_a_case(fp_tc, fp_result);
	}
	fclose(fp_tc);
	fclose(fp_result);
	
}

void read_a_case(FILE *TC,FILE *file_out)
{
	double result;
	int point_count, question_count, i;
	fscanf(TC, "%d %d\n", &point_count, &question_count);

	logprint("\n# point_count=%d question_count=%d\n", point_count, question_count);
	memset(&mPint, 0x00, sizeof(MPOINT)* 200010);
	mPint[1].depth = 0;
	mPint[1].prev_val = 1;

	for (i = 0; i < point_count-1; i++)
	{
		int temp_prev, current;
		fscanf(TC, "%d %d\n", &temp_prev, &current);
		//mPint[temp_prev].is_not_endpoint = 1;
		mPint[current].prev_val = temp_prev;
		if ((mPint[temp_prev].depth == 0x00 && temp_prev != 1) || mPint[temp_prev].depth == 0xEEEEEE)
			mPint[current].depth= 0xEEEEEE;
		else
		   mPint[current].depth = mPint[temp_prev].depth + 1;
	}

	for (i = 0; i < question_count; i++)
	{
		int temp_point1,temp_point2;
		fscanf(TC, "%d %d\n", &temp_point1, &temp_point2);

		if (mPint[temp_point1].depth == 0xEEEEEE)
		{
			finddepth(temp_point1);
		}

		if (mPint[temp_point2].depth == 0xEEEEEE)
		{
			finddepth(temp_point2);
		}

		if (mPint[temp_point1].depth > mPint[temp_point2].depth)
		{
			int temp_swap;
			temp_swap = temp_point1;
			temp_point1 = temp_point2;
			temp_point2 = temp_swap;
		}

		while (mPint[temp_point2].depth > mPint[temp_point1].depth)
		{
			temp_point2 = mPint[temp_point2].prev_val;
		}

		if (temp_point2!=temp_point1)
			fprintf(file_out,"0\n");
		else if (temp_point2 == temp_point1)
			fprintf(file_out, "1\n");
	}
}

void finddepth(int num)
{
	int n=0,i;
	memset(temp_num, 0x00, sizeof(int)* 210000);
	while (mPint[num].depth == 0xEEEEEE)
	{
		temp_num[n] = num;
		n++;
		num = mPint[num].prev_val;
	}

	for (i = 0; i < n; i++)
	{
		mPint[temp_num[i]].depth = mPint[num].depth + (n - i);
	}
}
