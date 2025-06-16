// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exoplanet.h"

// this function will load in the exoplanets csv data file
int load_exoplanets(const char *file_name, struct exoplanet array[], int max_count) {
    // open the csv file
    FILE *fp = fopen(file_name, "r");

    // this checks if the file could not be opened
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
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