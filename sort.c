// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exoplanet.h"

// this function does the insertion sort and prints out the results
void insertion_function(struct exoplanet array[], int number_of_elements) {
    // perform insertion sort
    struct_insertion_sort(array, number_of_elements);

    printf("\n\nInsertion Sort Results:\n");

    // print the first and last 10 elements in the sorted list
    // NOTE: the exoplanet's id will keep its original id it got assigned to when it was being stored into the unsorted list
    printf("The first 10 struct elements in the SORTED list:\n");
    for (int i = 0; i < 10 && i < number_of_elements; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[i].id, array[i].name, array[i].mass);
    }

    printf("\nThe last 10 struct elements in the SORTED list:\n");
    for (int i = number_of_elements - 10; i < 4389; i++) {
        printf("Row %d: Planet Name = [%s], Planet Mass (Earth Mass) = [%0.9f]\n", array[i].id, array[i].name, array[i].mass);
    }
}

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
        while ((j > -1) && (array[j].mass > element.mass)) {
            array[j + 1] = array[j];    // perform the swap (move the larger number to the right-most position)
            j--;                        // subtract 1 from j
        }

        array[j + 1] = element;         // complete the swap (move the smaller number to the left-most position)
    }

    // return with a sorted list of structs
    return;
}