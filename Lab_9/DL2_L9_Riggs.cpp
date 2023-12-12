/*
  Author:  Austin Riggs / Paul Thayer
  Course:  COSC1337
  Section: DL2
  Lab:     9
  Topic:   search and sort algorithms: write, understand, test; show table of algorithm times as array size increases
*/

/*
  Lab 9 on search, sort, algorithm performance:
  Seek places to add new code by searching on "<new code>"
  Seek places to change or modify by searching on "<modify code>"
  NO USER INPUT EXPECTED - OUTPUT ONLY - TEST RESULTS - NARRATION AND TIMINGS
*/

#include <random> // for srand, rand
#include <iostream>
#include <iomanip>

using namespace std;

// The searching and sorting algorithms will be tested on a big array filled with random numbers.
// To test on various array sizes, increasing amounts of the big array will be used.
// A table will display results of how long it takes to complete a task on various sizes of test data.
const int START{1000};
const int BIGSIZE{64000};
int bigArray[BIGSIZE]{};
const int testSizes[]{START*1, START*2, START*4, START*8, START*16, START*32, BIGSIZE, 0}; // 0 is a sentinel
// All numbers inside testSizes MUST BE less than or equal to BIGSIZE

const int TARGET{-1}; // TARGET, number to search for.
/*
  TARGET never found by search algorithms, because TARGET never in array search on.
  -1 is not returned by rand(), not in range of 0 - 2 ^ 16 -1 which is the range output by rand()
  Use TARGET to demonstrate worst-case search performance - TARGET is not in array.
*/

// array helper functions:
void show_array(int array[], int size, const string &msg="") { // displays every element in array
  cout<<msg;
  for (int i{}; i<size; ++i)
    cout << setw(2) << array[i]; // assumes small numbers; no line breaks / endl are output
  cout << endl;
}

// Useful to measure unsorted-ness of the array
int unorderedCount(int array[], int size) {
  // returns count of out-of-order adjacent pairs; will be 0 if properly sorted.
  int unsorted_adjacent_pairs{};
  for (int i=0; i<(size-1); ++i)
    if (array[i]>array[i+1]) ++unsorted_adjacent_pairs;
  return unsorted_adjacent_pairs;
}

bool verifySorted(int array[], int size) { // Useful to verify that array is really sorted!
  // returns true if array is in ascending order, else false.
  for (int i=0; i<(size-1); ++i)
    if (array[i]>array[i+1]) return false; // return false as soon as unordered pair detected
  return true;
}

// To display the table of timing results, use these to set column widths:
const int AlgorithmNameMaxWidth{16}; // maximum column width to display algorithm names
const int TestSizeWidth{12};         // maximum column width to display time to run algorithms
const int DurationWidth{TestSizeWidth};
// Adjust these column widths if/as needed so the table columns are aligned.

// Each selection sort below does the same algorithm. The difference is in
// how well it documents its operation. See code after main.
const string SELECTION_SORT_NAME{"selection sort"};
void selection_sort_cryptic(int[], int); // from internet, not called
void selection_sort_text(int[], int);    // from our textbook, not called
void selection_sort(int[], int, bool);   // annotated, as expected for this lab, see below


const string MY_BUBBLE_SORT_NAME {"My Bubble Sort"};
void my_bubble_sort(int[], int, bool);    // expected for this lab <modify code>
void swap(int&, int&); // used to swap elements in my_bubble_sort


const string MY_INSERT_SORT_NAME{"My Insert Sort"};
void my_insert_sort(int[], int, bool);    // expected for this lab <modify code>

bool linear_search_array(int [], int, int, int&); // provided
void binary_search_array(int [], int, int, int&); // expected for this lab <modify code>

// This code helps to automate multiple test runs.

// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm1x(void sortAlgorithm(int [], int, bool),
                          int array[], int arraySize, bool verbose=false) {
  // Run sortAlgorithm once on array and return time elapsed in milliseconds.
  // This function is interesting. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int, bool)
  // The first parameter (in the caller) can be the name of a function being tested.
  // This reduces redundant code. The same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)

  // fill array with random, unsorted numbers to be sorted
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock();  // get the start time, in milliseconds
  sortAlgorithm(array, arraySize, verbose);  // ALGORITHM UNDER TEST
  int stopTime = clock();   // get the stop time, in milliseconds
  float duration = stopTime - startTime;

  int unordered_pairs = unorderedCount(array, arraySize);
  if (unordered_pairs != 0)
    return -unordered_pairs; // return a negative count of unordered pairs to indicate sort failure
  else
    return duration;
}

void testSortAlgorithmNx(void sortAlgorithm(int [], int, bool), string sortName,
                         int array[], int arraySize, bool verbose=false) {
  // call testSortAlgorithm1x for each size in testSizes; display results on one line of table
  cout << endl << setw (AlgorithmNameMaxWidth) << left << sortName;
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm1x(sortAlgorithm, array, testSizes[testCount]);
}


// Copy/paste/modify/reuse this code as desired to test search algorithms.
// Because search is much faster than sort and duration is in milliseconds,
// the search is run retry times (defaults to 1000) and duration is divided by retry.
float testLinearSearch(int array[], int arraySize, int retry=1000) {
  bool found = false; // true if TARGET is found in array
  int foundAt = -1;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < retry; ++repeat) // repeat test 1000 times to increase duration
    found = linear_search_array(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  float duration = stopTime - startTime;
  return duration/retry; // divide duration by 1000 to get time for single search
}

// Austin's testBinarySearch
float testBinarySearch(int array[], int arraySize, int retry=100000) {
  int foundAt = -1;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < retry; ++repeat) {
    binary_search_array(array, arraySize, TARGET, foundAt);
  }
  int stopTime = clock();
  float duration = stopTime - startTime;
  return duration/retry; // divide duration by 100,000 to get time for single search
}

void testAlgorithms(int array[], int arraySize, bool verbose=false) {
  // Draws a table of results for each algorithm tested.
  // Initially, the heading for the table is displayed:
  cout << setw (AlgorithmNameMaxWidth) << left << "Algorithm";
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(TestSizeWidth) << right << testSizes[testCount];
  cout << endl << string(AlgorithmNameMaxWidth, '=');
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";

  // In testSortAlgorithmNx, the name of the sort function is passed as a parameter.
  // Do the same thing for your sort algorithms. It works as long as your sort algorithm
  // returns void and is declared as: void sort(int array[], int size).

  testSortAlgorithmNx(selection_sort, SELECTION_SORT_NAME, array, arraySize); // provided
  // call to test your first sort algorithm. <modify code> rename my sort 1
  testSortAlgorithmNx(my_bubble_sort, MY_BUBBLE_SORT_NAME, array, arraySize);
  // call to test your second sort algorithm. <modify code> rename my sort 2
  testSortAlgorithmNx(my_insert_sort, MY_INSERT_SORT_NAME, array, arraySize);

  cout<<"\n--------"; // separator between sort algorithms and search algorithms

  // Here, the provided linear search is tested...
  cout << endl << setw (AlgorithmNameMaxWidth) << left << "linear search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);

  // Edited to give output 7 decimal places
  cout << endl << setw (AlgorithmNameMaxWidth) << left << "binary search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount) {
    cout << setw(DurationWidth) << right << setprecision(7) << fixed
         << testBinarySearch(array, testSizes[testCount]);
  }
}


void testSortOnSmallArray(void sortAlgorithm(int [], int, bool), string sortName) {
  int smallArray[] {7, 9, 3, 1, 8, 6, 2}; // for testing purposes

  const int SMALLSIZE = sizeof(smallArray)/sizeof(smallArray[0]);

  show_array(smallArray, SMALLSIZE, sortName + " start: smallArray is: ");
  sortAlgorithm(smallArray, SMALLSIZE, true); // true means verbose, show details
  show_array(smallArray, SMALLSIZE, sortName + " stop:  smallArray is: ");
  cout << ((verifySorted(smallArray, SMALLSIZE)) ?
    "Verified: smallArray is sorted.\n\n" :
    "Oops!!!: smallArray is NOT sorted.\n\n");
}

int main () {
  srand(time(0));  // seed the random number generator only once.

  // When first implementing your algorithm, test it on a very small array.
  // The verbose flag will be set to true in testSortOnSmallArray, so step-by-step
  // progress will be displayed. This describes how the sort is working.

  cout << "Test sorting algorithms on small array:\n\n";
  // testSortOnSmallArray provides a small array to test on and sets verbose=true
  testSortOnSmallArray(selection_sort, SELECTION_SORT_NAME);
  testSortOnSmallArray(my_bubble_sort, MY_BUBBLE_SORT_NAME);
  testSortOnSmallArray(my_insert_sort, MY_INSERT_SORT_NAME);
  // return 0; // When initially testing your sort code, you may want to return here.

  // After sort code works on small array, test performance on bigArray.
  float duration = 0.0; // time in milliseconds
  // Startup code performs a single test run using the full size of bigArray
  duration = testSortAlgorithm1x(selection_sort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "Linear search of bigArray took: "
       << setw(8) << duration << " milliseconds.\n";

  duration = testBinarySearch(bigArray, BIGSIZE);
  cout << "Binary search of bigArray took: "
       << setw(8) << duration << " milliseconds.\n\n";

  // Test the algorithms on many ever longer list of numbers. Only one array is needed.
  //  Lengths of 1000, 2000, 4000, 8000, 16000, 32000, 64000 are tested and displayed.
  testAlgorithms(bigArray, BIGSIZE);

  return 0;
} // end of main

// Austin's verison of bubble sort
void my_bubble_sort(int array[], int size, bool verbose=false) {
  int pass_count{}; // used to show outter loop iterations and display current array state
  bool swapped = true; // flag to test if swapping occured
  for (int indexSorted = size - 1; indexSorted > 0; indexSorted--) {
  // outter loop starts at size of the array - 1 decreases by 1 each iteration
  // the largest value in the array will be at array[size - 1] at the end of pass #0
    swapped = false; // resets flag
    for (int searchIndex{}; searchIndex < indexSorted; searchIndex++) {
    // the inner loop works from the first array index forwards towards indexSorted, pushing an element with the
    // greatest value to the end of the array every inner loop cycle
      if (array[searchIndex] > array[searchIndex+1]) { // checks if value at left index is greater than right index
        if(verbose) { // if verbose is true, the following message is displayed to user
		    cout << "Element at array[" << searchIndex << "] = " << array[searchIndex] << " is greater than "
               <<  "element at array[" << searchIndex+1 << "] = " << array[searchIndex+1] << endl;
		    cout << "After swap: array[" << searchIndex << "] = " << array[searchIndex+1] << " and "
               << "array[" << searchIndex+1 << "] = " << array[searchIndex] << endl << endl;
        }
        swap(array[searchIndex], array[searchIndex+1]); // swap helper funcrtion used to swap array values
        swapped = true; //  swapped flag turned off
	  }
    }
    if(!swapped) return; // if no swapping occured, array is in order and function ends

    if(verbose) { // if verbose is true, user is shown pass count and current array state
      cout << "After pass #" << pass_count << ", array is: ";
	  show_array(array, size);
	  cout << endl << endl;
	  pass_count++;
	}

  }
}

// Austin's version of insert sort
void my_insert_sort(int array[], int size, bool verbose=false) {
  // currentSmallest used to store values at array[nextIndex], these values are compared to array[currentIndex]
  // values. If its value is smaller, it will be pushed towards the front of array and inserted there
  int currentSmallest{};
  int currentIndex{}; // starts at array[0]
  int pass_count{}; // used to show number of outter loop iterations in verbose mode
  for (int nextIndex{1}; nextIndex < size; nextIndex++) { // nextIndex starts at array[1]
    currentSmallest = array[nextIndex];

     if(verbose) {
       cout << "array[" << nextIndex << "] = " << array[nextIndex] << ". Value "
            << currentSmallest << " assigned to currentSmallest." << endl;
	}
    currentIndex = nextIndex-1;
    while (currentIndex >= 0 && array[currentIndex] > currentSmallest) {
      if(verbose) {
         cout << "array[" << currentIndex << "] = " << array[currentIndex] << " is greater than currentSmallest = "
              << currentSmallest << endl;
         cout <<"array[" << currentIndex+1 << "] reasigned to hold value: " << array[currentIndex]
				  << ", from array[" << currentIndex << "] = " << array[currentIndex] << endl << endl;
	  }
      array[currentIndex+1] = array[currentIndex]; // value of currentIndex assigned to following index
      currentIndex--;
	}
	array[currentIndex+1] = currentSmallest; // After while loop, currentIndex+1 assigned currentSmallest value
	if(verbose) {
      cout << "array[" << currentIndex+1 << "] reasigned to hold value: " << currentSmallest << ", from currentSmallest."
           << "\n\nAfter pass #" << pass_count << ", array is: ";
	   show_array(array, size);
	   cout << endl << endl;
      pass_count++;
	}
  }
}

// A search might be desired on a non-array, non-contiguous data structure; our algorithms only work on arrays
// Your new search algorithm isn't linear search - which is provided here.
bool linear_search_array(int array[], int size, int target, int &position) {
  for (int offset = 0; offset < size; ++offset)
    if (array[offset] == target) // found it!
      {position=offset; return true;}
  position = -1;
  return false;
}

// Austin's version of binary search
void binary_search_array(int array[], int size, int target, int &position) {
  int startIndex{}, middleIndex{}, endIndex{size-1};
  while(startIndex <= endIndex) {
    middleIndex = (startIndex + endIndex) / 2;
    if(array[middleIndex] == target) {
      position = middleIndex;
      return;
	}
	else if ( array[middleIndex] > target) {
	  endIndex = middleIndex - 1;
	}
	else {
      startIndex = middleIndex + 1;
	}
  }
  position = -1;
}

// This is a selection sort from an algorithm encyclopedia. Can you understand what this is doing?
// This code is VERY CRYPTIC! Not useful for learning. Not self-documenting. No comments. Not called.
// If your algorithms look like this, you will lose points!!!
void selection_sort_cryptic(int array[], int size) {
  int i, x, val;
  for (i = 0; i < (size - 1); i++) {
    x = i;
    val = array[i];
    for (int j = i + 1; j < size; j++) {
      if (array[j] < val) {
        val = array[j];
        x = j;
      }
    }
    array[x] = array[i];
    array[i] = val;
  }
}

// Your new sort algorithm cannot be selection sort, which is provided.
// This is the selection sort from our textbook, not called.
void selection_sort_text(int array[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// used to swap element values in my_bubble_sort
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// selection sort described in great detail. A good model for your code.
// The verbose option / flag causes a detailed display of its operation for each pass.
void selection_sort(int array[], int size, bool verbose=false) {
  if (size<=1) return; // no work to do
  int minIndexSoFar = 0, minValueSoFar{array[0]};
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the remaining unsorted portion of the array.
     if (array[seekMinIndex] < minValueSoFar) { // found a smaller min value than before, save it for now
        if (verbose) cout << "  prev min in array[" << minIndexSoFar << "]=" << minValueSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        if (verbose) cout << "; new min in array[" << minIndexSoFar << "]=" << minValueSoFar << endl;
      }
    } // The smallest value in the unsorted portion of the array found and is at array[minIndexSoFar]

    if (verbose) {
      cout << "  swap leftwards in array[" << unsortedIndex << "]=" << array[unsortedIndex];
      cout << " with min in array[" << minIndexSoFar << "]=" << array[minIndexSoFar] << endl;
    }

    // Swap original left-most unsorted value with minimum value just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;

    if (verbose) {
      cout << "After pass #" << unsortedIndex << ", array is: ";
      show_array(array, size);
      cout << endl;
    }
    // ... continue for loop, seeking minimum value in the smaller remaining portion.
  } // for
}




/* TEST OUTPUT:

*/