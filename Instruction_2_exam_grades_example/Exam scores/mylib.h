#define MAXLINE 500

void M_ReadGrades(char* input_filename,int *count,float *grades,int *studID);

void M_AvgGrade(int *count,float *grades,float *avg);

void M_std(int *count,float *grades,float *avg,float *std);

void M_extrema(int *count,float *grades,float *max,float *min);

void M_WriteResults(char* output_filename,int *count,float *avg,float *std,float *max,float *min,float *grades,int *studID);
