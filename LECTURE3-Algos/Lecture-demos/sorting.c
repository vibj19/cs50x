//Selection sort - Go through each element in array, finding smallest and swapping every single time
// For i from 0 to n-1
    // Find smallest number between numbers [i] and numbers [n-1]
    // Swap smallest number with numbers [i]
    // n(n-1)/2 = (n^2/2) - (n/2) -> O(n^2) (order of n squared upper bound=lower bound; theta); even in best case of sorted list, spend time verifying


// Bubble sort - Keep solving small problems in pairs
// Repeat n-1 times
    // for i from 0 to n-2
        //If numbers[i] and numbers [i+1] out of order
        //Swap them
    //If no swaps
        //Quit

    //(n-1) repetitions * (n-1) times = (n-1)^2 = O(n^2) (order of n squared upper bound; lower bound O(n))

//count number of comparisons to compare efficiency of algorithms

// Recursion -- Function calling itself

//Merge Sort -- Recursive methodw
//If only one number
    //Quit
//Sort left half of numbers
//Sort right half of numbers
//Merge sorted halves

    // O(n*log(n)) upper bound = lower bound (theta); uses a lot more memory
