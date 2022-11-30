// longest_palindromic_substring_a.cpp
// Задача: в заданной строке найти самую длинную подстроку-палиндром.
// Алгоритм решения: начиная с длины строки (и уменьшая её до 2) перебирать все подстроки заданной длины,
// проверяя, являются ли они палиндромами.
#include <cstddef>

/// Функция проверяет, является ли содержимое диапазона строки палиндромом.
bool is_palindrome(const char *begin, const char *end)
{
  while (begin < end)
    if (*begin++ != *--end)
      return false;

  return true;
}

/// Найти самую длинную подстроку-палиндром в диапазоне строки.
/// Возвращает длину найденной подстроки, по указателю found записывает указатель на начало найденной подстроки.
std::size_t longest_palindrome(const char *begin, const char *end, const char **found)
{
  for (auto n = end - begin; n > 1; --n) // длина палиндрома
  {
    for (auto pos = begin; end - pos >= n; ++pos) // начало подстроки
    {
      if (is_palindrome(pos, pos + n)) // палиндром?
      {
        *found = pos;
        return n;
      }
    }
  }

  return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Тестирование
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

/// В заданном объекте std::string найти самую длинную подстроку-палиндром
/// и вернуть её в виде нового объекта std::string.
string longest_palindrome(const string &text)
{
  const char *pos = nullptr;
  const auto len = longest_palindrome(text.data(), text.data() + text.size(), &pos);
  return string(pos, pos + len);
}

/// Проверка результата для тестовых строк.
int test_longest_palindrome()
{
  if (longest_palindrome("this isn't a text with no palindromic substrings") != "t a t")
    return 1;
  if (longest_palindrome("there is no word redivider in English") != " redivider ")
    return 2;
  if (longest_palindrome("who knows what \"detartrated\" means?") != " \"detartrated\" ")
    return 3;
  if (longest_palindrome("saippuakalasalakauppias is longer than"
                         "saippuakivikauppias but what about"
                         "kuulilennuteetunneliluuk?") != "kuulilennuteetunneliluuk")
    return 4;
  if (longest_palindrome("blast") != "")
    return 5;
  return 0;
}

int main()
{
  auto test = test_longest_palindrome();
  cout << test << endl;
  assert(test == 0);
  return EXIT_SUCCESS;
}