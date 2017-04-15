/* example of writing to a file providing error checking  */

#include <stdio.h>

int main(){

	FILE *fp;   				/* declare a pointer to a FILE  */
	char lname[31];
	char fname[31];
	double salary;
	char position[31];
		int i;

	fp = fopen("records.dat", "w");  	/* open file records.dat  */
	if(fp){    							/* same as  if( fp != NULL ) */
		for(i = 0; i < 3; i++){
			printf("Last Name: ");
			gets(lname);
			printf("First Name: ");
			gets(fname);
			printf("Salary: ");
			scanf("%lf", &salary);
			while(getchar() != '\n');   /* clear the input buffer */
			printf("Position: ");
			gets(position);
			fprintf(fp, "%s,%s:%.2lf,%s\n",
				lname, fname, salary, position);
		}
		printf("%d records written to the file\n", i);
		fclose(fp);
	} else
		printf("Cannot open records.dat file\n");
}

