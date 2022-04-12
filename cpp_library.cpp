/**
 * Author: lcbcfoo (Lucas Castro)
 *
 * This library was completely implemented by me as
 * a CPP utility library for coding competitions.
 * It contains the implementation of common algorithms, math operations
 * macros and other utilities.
 *
 * Do not use it if the competition does not allow it!
 * 
 */


/**
 *
 * Common includes
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

/*
 *  __  __                          
 * |  \/  |                         
 * | \  / | __ _  ___ _ __ ___  ___ 
 * | |\/| |/ _` |/ __| '__/ _ \/ __|
 * | |  | | (_| | (__| | | (_) \__ \
 * |_|  |_|\__,_|\___|_|  \___/|___/
 */
                                  


/**
 *
 * Useful defines
 *
 */

#define ll long long int
#define ull long long unsigned int


/**
 *
 * Debug Macros
 *
 */

#ifdef DEBUG
#define DEBUG(x) (std::cout << (x))
#else 
#define DEBUG(x)
#endif


/*           _                  _ _   _                   
 *     /\   | |                (_) | | |                  
 *    /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  ___ 
 *   / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \/ __|
 *  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | \__ \
 * /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|___/
 *              __/ |                                     
 *             |___/                                      
 */


/*
 *
 * Count elements in array
 * Returns a map of all elements and their frequencies
 *
 */

template<class T>
std::map<T, ull> count_elements(std::vector<T> v) {
    std::map<T, ull> counters = std::map<T, ull>();
    for(auto i: v)
    {
        ++counters[i];
    }
    return counters;
}

/*
 *
 * Find the mode of a vector and its frequency
 * Return a pair of the mode of a vector and its frequency
 * Requires count_elements
 *
 */

template<class T>
std::pair<const int, long long unsigned int> vector_mode(std::vector<T> v) {
    auto frequency_count = count_elements<T>(v);
    auto pr = std::max_element
    (
        std::begin(frequency_count), std::end(frequency_count),
        [] (auto & p1, auto & p2) {
            return p1.second < p2.second;
        }
    );
    return *pr;
}
