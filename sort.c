// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "exoplanet.h"

// this function is the insertion sort algorithm that uses structs
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
        // if the other element is greater than the current element, then perform a swap
        while ((j > -1) && (array[j].mass > element.mass)) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = element;
    }

    // return with a sorted list of structs
    return;
}