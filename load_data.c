#ifdef _WIN32
    #include <direct.h>      // For _mkdir, _rmdir
    #include <io.h>          // For _access
    #define MKDIR(path) _mkdir(path)
    #define RMDIR(path) _rmdir(path)
    #define ACCESS(path) _access(path, 0)
#else
    #include <sys/stat.h>    // For mkdir
    #include <unistd.h>      // For access, rmdir
    #define MKDIR(path) mkdir(path, 0777)
    #define RMDIR(path) rmdir(path)
    #define ACCESS(path) access(path, F_OK)
#endif

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "exoplanet.h"

// this function will load in the exoplanets csv data file
int load_exoplanets(const char *file_name, struct exoplanet array[], int max_count) {
    // open the csv file
    FILE *fp = fopen(file_name, "r");

    // this checks if the file could not be opened
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        exit(-1);   // exit the program so that it doesn't do anything weird
    }
    else {
        printf("Success: File was opened.\n");
    }

    // initialize variables
    char line[10000];       // this reads in each line from the csv file
    int line_counter = 0;   // this counts the lines in the csv file
    int count = 0;          // this makes sure to not use all the data in the csv file
    int null_counter = 0;   // this counts the number of NULL values in a column
    int exo_counter = 0;    // this counts the number of exoplanets that have a non-NULL mass

    // a loop that reads in each line from the csv file
    while ((fgets(line, sizeof(line), fp)) && (exo_counter < max_count)) {
        // start at line 20 since the previous lines is filled with comments
        if (line_counter > 19) {
            // initialize variables
            char *token;        // this retrieve the comma separated value
            char *tokens[12];   // this stores the comma separated values
            int i = 0;          // incrementer
            
            // get the first token
            token = strtok(line, ",");

            // loop until the token is NULL and the incrementer reaches 12
            while ((token != NULL) && (i < 12)) {
                // store the token in the token array
                tokens[i++] = token;

                // get the next token
                token = strtok(NULL, ",");
            }

            // check if the mass token is NULL or not and store it
            if (strcmp(tokens[2], "NULL") == 0) {
                // don't store anything since it's easier to leave the data out
                null_counter++;
            }
            else {
                // store the data if the mass token has non-NULL value
                array[exo_counter].id = exo_counter;
                array[exo_counter].name = strdup(tokens[0]);
                array[exo_counter].mass = atof(tokens[2]);    // Convert string to float

                exo_counter++;
            }
        }

        line_counter++;
    }

    // close the csv file after running the above code
    fclose(fp);

    // check if the list has data stored
    if (exo_counter <= 0) {
        printf("Error: Data from the file was not stored.\n");
    }
    else {
        printf("Success: Data from the file was stored.\n\n");
    }

    // return the actual number of exoplanets
    return exo_counter;
}

// this function prints out the first and last 10 elements of a list
void print_list(struct exoplanet array[], int number_of_elements, char *string) {
    // NOTE: the exoplanet's id will keep its original id it got assigned to when it was being stored into the unsorted list
    printf("The first 10 struct elements in the %s list:\n", string);
    for (int i = 0; i < 10 && i < number_of_elements; i++) {
        printf("Planet #%d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[i].id, array[i].name, array[i].mass);
    }

    printf("\nThe last 10 struct elements in the %s list:\n", string);
    for (int i = number_of_elements - 10; i < 4389; i++) {
        printf("Planet #%d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[i].id, array[i].name, array[i].mass);
    }

    return;
}

// this function stores the sorted results in an output file
void store_results(struct exoplanet array[], int number_of_elements, char *string) {
    printf("\nCreating txt file to store the %s Sort algorithm's results.\n", string);

    // initialize variables
    char file_name[200];
    FILE *fp;
    char directory_name[] = "results/";

    // construct full path for output file
    strcpy(file_name, directory_name);
    strcat(file_name, string);
    strcat(file_name, " Sort Results.txt");
    //printf("\n%s\n", file_name);

    printf("Success: txt file created. Now opening the txt file.\n");

    // open the file
    fp = fopen(file_name, "w");

    // check if the file is opened
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        exit(-1);   // exit the program so that it doesn't do anything weird
    }
    else {
        printf("Success: File was opened. Now storing the results in the txt file.\n");
    }

    // store the sorted list in the file
    for (int i = 0; i < number_of_elements; i++) {
        fprintf(fp, "Planet #%d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[i].id, array[i].name, array[i].mass);
    }

    printf("Success: The results are stored into the txt file. Now closing the txt file.\n");

    // close the file
    fclose(fp);

    printf("Success: txt file is closed. The results are stored in: %s Sort Results.txt.\n", string);

    return;
}

// this function creates a directory that stores the result files
void create_directory() {
    // initialize variables
    const char *directory_name = "results";

    printf("\nCreating directory to store results.\n");

    // check if the results directory exists
    if (ACCESS(directory_name) == 0) {
        printf("Warning: Results directory already exists. Deleting it...\n");

        // delete the existing results directory recursively
        #ifdef _WIN32
            if (system("rmdir /s /q results") != 0) {
                printf("Error: Failed to delete existing results directory.\n");
                exit(-1);
            }
        #else
            if (system("rm -rf results") != 0) {
                printf("Error: Failed to delete existing results directory.\n");
                exit(-1);
            }
        #endif

        printf("Success: Results directory deleted.\n");
    }

    // create a new results directory
    if (MKDIR(directory_name) == 0) {
        printf("Success: Results directory created.\n");
    }
    else {
        printf("Error: Failed to create results directory.\n");
        exit(-1);
    }

    return;
}