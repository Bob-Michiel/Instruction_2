/**********************************************************
main.c, analyses of exam grades, Michiel Oom, 5-2-2016, v1
**********************************************************/

#include <stdio.h>
#include "mylib.h"

int main( void )
{
	int count=0;			//Number of participated students
	float avg=0;			//Average of the scores
	float std=0;			//Standard deviation of the scores
	float max=-1;			//Lowest grade
	float min=11;			//Highest grade
	float grades[MAXLINE];	//List with scores
	int studID[MAXLINE];	//List with student identification numbers

	M_ReadGrades("grades.dat",&count,grades,studID); // 	Intitializes grades, studID and count from input file 

	M_AvgGrade(&count,grades,&avg); // Calculates avg

	M_std(&count,grades,&avg,&std); // Calculates std

	M_extrema(&count,grades,&max,&min); // Calculates max and min

	M_WriteResults("processed_results.dat",&count,&avg,&std,&max,&min,grades,studID); // Writes results to output file
	
	return 0;
}
