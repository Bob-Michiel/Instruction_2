/**********************************************************************************
mylib.c, functions for analysis of grades, Michiel Oom, 6-2-2016, v1
**********************************************************************************/

#include <stdio.h>
#include "mylib.h"
#include <math.h>

void M_ReadGrades(char* input_filename,int *count,float *grades,int *studID)
{
	int i=0;
	FILE *gradlist;
	

	if((gradlist=fopen(input_filename,"r"))==NULL)
		{
		printf("error\n");
		}

	while((fscanf(gradlist,"%i %f",&studID[i],&grades[i]))!=EOF)
	{
		i++;
	}

	fclose(gradlist);


	if(i>=MAXLINE)
	{
		printf("Warning: increase MAXLINE to %i/n",i);
	}
		

	*count=i;
}

void M_AvgGrade(int *count,float *grades,float *avg)
{
	float sum=0;

	for(int i=0;i<*count;i++)
	{
		sum+=grades[i];
	}

	*avg=sum/(*count);
	
}

void M_std(int *count,float *grades,float *avg,float *std)
{
	float sumsqr=0;

	for(int i=0;i<*count;i++)
	{
		sumsqr+=(grades[i]-*avg)*(grades[i]-*avg);
		*std=sqrtf(1.0/(*count-1)*sumsqr);
	}
}

void M_extrema(int *count,float *grades,float *max,float *min)
{
	for(int i=0;i<*count;i++)
	{
		if(grades[i]>*max)
		{
			*max=grades[i];
		}

		if(grades[i]<*min)
		{
			*min=grades[i];
		}
	}
}

void M_WriteResults(char* output_filename,int *count,float *avg,float *std,float *max,float *min,float *grades,int *studID)
{
	printf("%i students participated in the test.\n",*count);
	printf("The average grade was %f. \n",*avg);
	printf("With a standard deviation of %f. \n",*std);
	printf("The maximum score is %f.\n",*max);
	printf("The minimum score is %f.\n",*min);

	FILE *results;

	results=fopen(output_filename,"w");
	
	fprintf(results,"%i students participated in the test.\n",*count);
	fprintf(results,"The average grade was %f. \n",*avg);
	fprintf(results,"With a standard deviation of %f. \n",*std);
	fprintf(results,"The maximum score is %f.\n",*max);
	fprintf(results,"The minimum score is %f.\n",*min);

	for(int i=0;i<*count;i++)
	{
		fprintf(results,"%i %f\n",studID[i],grades[i]);
	}

	fclose(results);
	
}





