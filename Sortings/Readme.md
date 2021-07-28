# Sorting algorithms
* Sorting is the method/process by which we can arrange the elements based on specified factor in ascending or descending order.
## Importance of Sorting algorithms
* Sorted array helps to easily find maximum or minimum
* Searching for any element is easier.
* Applications in many broader real world applications.
## Bubble Sort
* Basic sort, uses bubbles as refrence and swap those bubbles until max is bought to right most position
* This sort has O(n^2) in Average, Worst Case while O(n) in
best case.
* Early stopping is added to stop when no swap occurs hence sorted.
* Number of swaps is also displayed at the end of run.
* **Ignoring vector display time and filling time**
* *With 20,000 elements it took 3.94 secs*
* *With 2,00,000 elements it took 5000 secs*
## Insertion sort
* Same as bubble sort but this time we find the place to insert the picked element in array and then swap
* Using a back reading approach to read from the back of the list to find the correct spot and insert
* It is most efficient algorithm to check if list is already sorted(For list of few elements) Gives O(n) time complexity.
* Sometimes works better or at lower end of O(n^2).