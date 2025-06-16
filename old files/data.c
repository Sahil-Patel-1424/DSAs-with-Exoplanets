// libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// create a struct that stores an exoplanet's information
struct exoplanet {
    int id;             // this helps differentiate between the exoplanets
    char *name;
    float mass;
};

// function prototypes
void struct_insertion_sort(struct exoplanet array[], int number_of_elements);

// this is the insertion sort algorithm that uses structs
void struct_insertion_sort(struct exoplanet array[], int number_of_elements) {
    // create a variable to store a struct element
    struct exoplanet element;

    // go through the array of structs
    for (int i = 1; i < number_of_elements; i++) {
        // initialize variables
        int j = i - 1;          // get the previous struct element
        element = array[i];     // store the current struct element

        // first check if j is greater than -1 to make sure we are accessing inside the list of structs
        // then check to see if the previous struct's element's value (mass) is greater than the current's struct element's value (mass)
        while (j > -1 && array[j].mass > element.mass) {
            array[j + 1] = array[j];    // perform the swap (move the larger number to the right-most position)
            j--;                        // subtract 1 from j
        }

        array[j + 1] = element;         // complete the swap (move the smaller number to the left-most position)
    }

    // return with a sorted list of structs
    return;
}

int main(void) {
    // open the csv file
    FILE* fp = fopen("PS_2025.06.02_17.07.37 - PS_2025.06.02_17.07.37.csv", "r");

    // initialize variables
    char line[10000];       // this reads in each line from the csv file
    int line_counter = 0;   // this counts the lines in the csv file
    int count = 0;          // this makes sure to not use all the data in the csv file
    int null_counter = 0;   // this counts the number of NULL values in a column
    int exo_counter = 0;    // this counts the number of exoplanets that have a non-NULL mass
    struct exoplanet struct_array[4389];    // this stores all of the exoplanets in an array of structs (4389 = total number of exoplanets that have non-NULL mass in csv file)

    // this checks if the file could not be opened
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(-1);   // exit the program so that it doesn't do anything weird
    }
    else {
        printf("Success: File was opened.\n\n");
    }

    // create a while loop that reads in each line from the csv file
    //while ((fgets(line, sizeof(line), fp)) && (count < 12)) {
    while ((fgets(line, sizeof(line), fp)) && (count < 38468)) {
    //while ((fgets(line, sizeof(line), fp)) && (count < 4389)) {
        // start at line 20 since the previous lines is filled with comments
        if (line_counter > 19) {
            //printf("%s\n\n", line);
            //printf("%d\n\n", count);

            // initialize variables
            char *token;                            // this retrieve the comma separated value
            char *tokens[10000];                    // this stores the comma separated values
            int i = 0;                              // incrementer
            //struct exoplanet array[38468];        // this stores all of the exoplanets in an array of structs (38468 = total number of exoplanets in csv file)

            // get the first token
            token = strtok(line, ",");

            // loop until the token is NULL and the incrementer reaches 12
            while ((token != NULL) && (i < 12)) {
                // store the token in the token array
                tokens[i++] = token;

                // get the next token
                token = strtok(NULL, ",");
            }

            /*
            printf("ID: %d\n", count);
            for (int j = 0; j < i; j++) {
                printf("Token %d: %s\n", j, tokens[j]);
            }

            printf("\n");
            */
            

            // print the selected tokens (this helps pick which data to store from each row in the csv file)
            //printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%s]\n", count, tokens[0], tokens[2]);

            // store the exoplanet's data
            //array[count].id = atoi(tokens[0]);
            //array[count].id = count;
            //array[count].name = tokens[0];
            //array[count].mass = atoi(tokens[2]);

            // check if the mass token is NULL or not and store it
            if (strcmp(tokens[2], "NULL") == 0) {
                //array[count].mass = 0;  // Set NULL to 0

                // don't store anything since it's easier to leave the data out
                null_counter++;
            }
            else {
                // store the data if the mass token has non-NULL value
                struct_array[exo_counter].id = exo_counter;
                struct_array[exo_counter].name = tokens[0];
                struct_array[exo_counter].mass = atof(tokens[2]);    // Convert string to float

                // print the selected tokens (this is to help pick which data to store from each row in the csv file)
                //printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[exo_counter].id, struct_array[exo_counter].name, struct_array[exo_counter].mass);
                
                exo_counter++;
            }

            // print the selected tokens (this is to help pick which data to store from each row in the csv file)
            //printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[count].id, array[count].name, array[count].mass);

            // NOTE (6/2/2025) [FIXED]: The way the code is set up, the tokens will take in values from the wrong columns if there are missing values in the row.
            // NOTE (6/9/2025): Had to manually add in NULL values to the csv file. The code should store in the data correctly now. should be able to start writing algorithms now.
            // NOTE (6/15/2025): Created a regular insertion sort algorithm and another one that uses structs. Both work. Next thing is to split this file's functionality into multiple files.
                // - Idea: Do the data storing in one file, the sorting algorithm in another file, and the printing and calling and stuff in another file.

            count++;
        }
        
        line_counter++;
    }

    // close the csv file after running the above code
    fclose(fp);



    // print the first and last 10 struct elements in the unsorted list of structs
    printf("The first 10 struct elements in the unsorted list:\n");
    for (int i = 0; i < 10; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }

    printf("\nThe last 10 struct elements in the unsorted list:\n");
    for (int i = 4379; i < 4389; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }


    
    // sort the unsorted list of structs
    struct_insertion_sort(struct_array, 4389);



    // print the first and last 10 struct elements in the sorted list of structs
    // NOTE: the exoplanet's id will keep its original id it got assigned to when it was being stored into the unsorted list of structs
    printf("\nThe first 10 struct elements in the sorted list:\n");
    for (int i = 0; i < 10; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }

    printf("\nThe last 10 struct elements in the sorted list:\n");
    for (int i = 4379; i < 4389; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }

    // exit the program
    return 0;
}