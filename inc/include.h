#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>
#include <exception>
#include <queue>

using string = std::string;
using ifstream = std::ifstream;
using ofstream = std::ofstream;

template<typename K, typename T>
using unordered_map = std::unordered_map< K, T>;

template<typename F, typename S>
using pair = std::pair< F, S>;

template< typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>> 
using priority_queue = std::priority_queue<T, Container, Compare>;

template<typename T>
using vector = std::vector<T>;

using runtime_error = std::runtime_error;
using size = int;
using path = long;


