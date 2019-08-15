/**
  * main.cpp
  * Programs based on binary search
  * occurence of a number.
  * Author: Aakash Chitroda
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief binarySearch: This function shall find the first occurence of a particular key.
 * @param v: Array of vectors in which key is to be searched.
 * @param key: Key to be searched.
 * @param searchFirst:  If true: Search the first Occurrence of a key.
 *                      If false: Searcg the last occurrence of a key.
 * @return -1: If key is not found
 *         >=0: Index of key if found in array of vectors.
 */
int binarySearch(const vector<int> &v, const int &key, bool searchFirst) {
    int low = 0;
    int high = static_cast<int>(v.size() - 1);
    int mid = -1;
    int result = -1;

    while (low <= high) {
        mid = (low + high)/2;
        if (key == v.at(mid)) {
            result = mid;
            if (searchFirst)
                high = mid - 1;
            else
                low = mid + 1;
        } else if (key <= v.at(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

/**
 * @brief findCount: This function shall count the number of occurence of a given key.
 * @param v: Array of vectors from which number of occurence of key has to be counted.
 * @param key: Key to be counted in a given array of vector.
 * @return Returns number of occurence of a given key.
 */
int findCount(const vector<int> &v, const int &key) {
    int first = binarySearch(v, key, true);
    int last = binarySearch(v, key, false);
    if (first < 0 || last < 0)
        return 0;
    return (last - first + 1);
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(18);
    v.push_back(20);
    cout << binarySearch(v,10, true) << endl;
    cout << binarySearch(v,10, false) << endl;
    cout << findCount(v, 10) << endl;
    return 0;
}
