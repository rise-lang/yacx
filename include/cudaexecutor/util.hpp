#ifndef CUDAEXECUTOR_UTIL_HPP_
#define CUDAEXECUTOR_UTIL_HPP_

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo> // operator typeid
#include <vector>
namespace cudaexecutor {

std::string load(const std::string &path);
template <typename T>
std::string to_comma_separated(const std::vector<T> &vector);
template <typename T> std::string type_of(const T &variable);

// https://stackoverflow.com/a/57812868
template <typename T>
struct is_string
    : public std::disjunction<
          std::is_same<char *, typename std::decay<T>::type>,
          std::is_same<const char *, typename std::decay<T>::type>,
          std::is_same<int, typename std::decay<T>::type>,
          std::is_same<const int, typename std::decay<T>::type>,
          std::is_same<std::string, typename std::decay<T>::type>> {};

template <typename T>
std::string to_comma_separated(const std::vector<T> &vector) {
  static_assert(is_string<T>::value, "vector element must be stringable");
  std::string result;
  if (!vector.empty()) {
    for (const auto &i : vector) {
      std::string element{i};
      result.append(element);
      result.append(", ");
    }
    result.substr(0, result.length() - 2);
  }
  return result;
}

template <typename T> std::string type_of(const T &variable) {
  return std::string(typeid(variable).name());
}
} // namespace cudaexecutor

#endif // CUDAEXECUTOR_UTIL_HPP_
