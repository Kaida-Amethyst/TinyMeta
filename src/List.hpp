
// List Provide a data structure to store a list of values
// Will support the following operations:
// 
// - [x] declear a list
// - [x] get the first element of the list
// - [ ] get the last element of the list
// - [ ] get the nth element of the list
// - [ ] get the length of the list
// - [ ] get the tail of the list (pop the first element)
// - [ ] init of the list (pop the last element)
// - [ ] reverse of the list
// - [ ] append of the list
// - [ ] concat of the list
// - [ ] trasnform the list
// - [ ] foldl the list
// - [ ] foldr the list
// - [ ] map the list
// - [ ] ... and more


namespace Meta {




template <typename T, T... values>
struct List;

/*
 * ElementType
 *  parameters:  typename T - Any Container Type
 *
 *  description: Return the element type of the container
 *
 *  example:     ElementType<List<int, 1, 2, 3>>  // return int
 *              ElementType<List<uint32_t, 1, 2, 0>> // return uint32_t
 *
*/
template <typename T>
struct ElementTypeT;

template <typename T, T... v>
struct ElementTypeT<List<T, v...>> {
  using type = T;
};

template <typename T>
using ElementType = typename ElementTypeT<T>::type;


/*
 * Front:
 *  parameters:  typename Container - Any Container Type
 *
 *  description: Return the first element of the container
 *
 *  example:     Front<List<int, 1, 2, 3>>  // return 1
 *                Front<List<uint32_t, 1, 2, 0>> // return 1
 *
 *
 */
template <typename Container>
struct FrontT;

template <typename T, T Head, T... Tails>
struct FrontT<List<T, Head, Tails...>> {
  static constexpr T value = Head;
};

template <typename Container>
static constexpr ElementType<Container> Front = FrontT<Container>::value;





}; // namespace meta
