#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using a struct to read and write

struct customer {
	char fname[20], lname[20];
	int acct_num;
	float acct_bal;

};

int main() {
	FILE *outfile;
	FILE *infile;
	struct customer input;

	//open Accounts file for writing
	outfile = fopen("accounts.dat", "w");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opening file accounts.dat\n\n");
		exit(1);
	}

	//Instructions to user
	printf("Enter \"stop\" for First Name to end program.");

	//Endlessly read from keyboard input and write to file
	while (1)
	{
		// Prompt user
		printf("\nFirst Name: ");
		scanf("%s", &input.fname);
		printf("\nLast Name: ");
		scanf("%s", &input.lname);
		// Exit if no first or last name provided
		if (strcmp(input.fname, "stop") == 0)
			exit(1);

		//Continue reading from keyboard
		printf("Account# : ");
		scanf("%d", &input.acct_num);
		printf("Acct Bal: ");
		scanf("%f", &input.acct_bal);

		//Write entire struct to Accounts file
		fwrite(&input, sizeof(struct customer), 1, outfile);
		if (outfile == NULL) 
		{
			fprintf(stderr, "\nError opening accounts.dat\n\n");
			exit(1);
		}


	}
    // Open Accounts file for reading
	infile = fopen("accounts.dat", "r");
    if (infile == NULL)
	    {
	    	fprintf(stderr, "\nError opening accounts.dat\n\n");
			exit(1);
	    }

	while (fread (&input, sizeof(struct customer), 1, infile))
		printf("Name: %10s %10s  Account Number: %8d  Balance: %8.2f\n", input.fname, input.lname, input.acct_num, input.acct_bal);
return 0;
}