// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  "exoplanet.h"

#define MAX_PLANETS 4389    // this is the actual number of exoplanets in the csv file

int main(void) {
    // initialize variables
    struct exoplanet struct_array[MAX_PLANETS];      // a list of structs
    const char *file_name = "PS_2025.06.02_17.07.37 - PS_2025.06.02_17.07.37.csv";      // the csv file
    struct exoplanet insertion_struct[MAX_PLANETS];     // used for insertion sort

    // load the csv file and return a number to see if the data was stored
    int count = load_exoplanets(file_name, struct_array, MAX_PLANETS);
    if (count < 0) {
        return -1;
    }

    // Print the first and last 10 elements in unsorted list
    printf("The first 10 struct elements in the UNSORTED list:\n");
    for (int i = 0; i < 10 && i < count; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }

    printf("\nThe last 10 struct elements in the UNSORTED list:\n");
    for (int i = count - 10; i < 4389; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", struct_array[i].id, struct_array[i].name, struct_array[i].mass);
    }

    // create multiple copies of the unsorted list
    for (int i = 0; i < count; i++) {
        insertion_struct[i] = struct_array[i];
    }

    // do insertion sort
    insertion_function(insertion_struct, count);

    // exit the program
    return 0;
}