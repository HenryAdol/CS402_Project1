#include <vector>
#include <random>
#include <concepts>
#include <type_traits>


#ifndef Henry_Chen_PROJECT1
#define Henry_Chen_PROJECT1

using namespace std;



/*** Helper Functions ***/
/* DO NOT MODIFY THIS FUNCTION */
inline unsigned int get_rand_index(unsigned int len) {
    srand(time({}));
    return static_cast<unsigned int>(std::rand() % len);
}


/*** STUDENT HELPER FUNCTIONS HERE ***/
/* You may write your own custom helper functions
 * in order to make your implementations easier.
 */

template <typename T>
void radix_sort_nonnegative(vector<T>& list) {
    vector<T> zero_bucket;
    vector<T> one_bucket;

    // Go through each bit position
    for (int bit = 0; bit < 32; ++bit) {
        zero_bucket.clear();
        one_bucket.clear();

        // Check the current bit and then place the number in its right bucket
        for (T item : list) {
            if (((item >> bit) & 1) == 1) {
                one_bucket.push_back(item);
            } else {
                zero_bucket.push_back(item);
            }
        }

        // Add the numbers back to the original list
        list.clear();
        list.insert(list.end(), zero_bucket.begin(), zero_bucket.end());
        list.insert(list.end(), one_bucket.begin(), one_bucket.end());
    }
}



/*** END STUDENT HELPER FUNCTIONS ***/





/*** DO NOT MODIFY BELOW ***/
/*** Main Functions for Students to Implement ***/

/** Helper type for integrals only **/
template<class T>
concept Integral = is_integral<T>::value;


/* Bubble Sort */
template<typename T>
void bubble_sort(vector<T> &list, bool descending = false);

/* Selection Sort */
template<typename T>
void selection_sort(vector<T> &list, bool descending = false);

/* Insertion Sort */
template<typename T>
void insertion_sort(vector<T> &list, bool descending = false); 

/* Quick Sort */
template<typename T>
void quicksort(vector<T> &list, bool descending = false);

/* Merge Sort */
template<typename T>
void merge_sort(vector<T> &list, bool descending = false);

/* Your Hybrid Sort */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending = false);

/* Binary Radix Sort */
template<Integral T>
void binary_radix_sort(vector<T> &list, bool descending = false);

/* Base B Radix Sort */
template<Integral T> 
void radix_sort(vector<T> &list, unsigned int base = 10, bool descending = false);



#endif
