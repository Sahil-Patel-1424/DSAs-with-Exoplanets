# DSAs-with-Exoplanets
I am utilizing NASA's Exoplanet Archive (https://exoplanetarchive.ipac.caltech.edu/) data to create sorting algorithms that sort the data based on the exoplanet's mass.

# Insertion Sort
The Insertion Sort algorithm is a straightforward sorting algorithm that sorts a list one element at a time. It works similarly to how you would sort playing cards in your hand - by dividing them into two groups: a sorted group and an unsorted group. You then take one card from the unsorted group and insert it into the correct position in the sorted group. Here is how the algorithm works:

1. You start with the second element in the list because you can assume that the first element is already sorted.
2. Compare the second element with the first element. If the second element is smaller, then you swap their positions.
3. Move on to the third element in the list and compare it with the first two elements before it. Then, you insert the third element into its correct position.
4. Continue this process for each element in the entire list until the list is sorted.
  
<br>
Since the data I used is randomly ordered, the Time Complexity of this Insertion Sort algorithm is O(n<sup>2</sup>). I chose the Insertion Sort algorithm as a baseline for comparing against more advanced sorting algorithms. It is a simple and easy program to implement, but its efficiency drops as the list grows larger, especially when compared to other sorting algorithms.

<br> <br>
More information on the Insertion Sort algorithm: https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/
