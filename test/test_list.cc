#include "../Meta.hpp"


using namespace Meta;

void test1() {
  using List1 = List<int, 3, 3, 2, 1>;
  using List2 = List<unsigned int, 9, 0, 82, 7>;
  using List3 = List<char, 6, 13, -32, 11>;

  static_assert(Trait::IsSame<ElementType<List1>, int>,
                "ElementType<List1> is not int");
  static_assert(Trait::IsSame<ElementType<List2>, unsigned int>,
                "ElementType<List2> is not unsigned int");
  static_assert(Trait::IsSame<ElementType<List3>, char>,
                "ElementType<List3> is not char");

  static_assert(Front<List1> == 3, "Front<List1> is not 3");
  static_assert(Front<List2> == 9, "Front<List2> is not 9");
  static_assert(Front<List3> == 6, "Front<List3> is not 6");
}

#include <iostream>
template <typename T>
void printArg() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main() {
  test1();
  printArg<ElementType<List<int, 1, 2, 3>>>();
  return 0;
}
