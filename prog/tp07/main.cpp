#include <iostream>

/*
			Factorielle
*/

template <unsigned int i>
struct Factorielle {
	static const unsigned int value = i * Factorielle<i-1>::value;
};
template <>
struct Factorielle<0> {
	static const unsigned int value = 1;
};




/*
			Liste de types
*/

/* List definition */
template <typename H, typename T>
struct TypeList {
	typedef H Head;
	typedef T Tail;
};
struct NullType {};

/* Get type in L at index i */
template <typename L, int i>
struct TypeAt {
	typedef typename TypeAt<typename L::Tail, i-1>::Result Result;
};
template <typename L>
struct  TypeAt<L, 0> {
	typedef typename L::Head Result;
};
template <int i>
struct  TypeAt<NullType, i> {
	typedef void Result;
};

/* Get L lenght */
template <typename L>
struct Lenght {
	static const int result = 1 + Lenght<typename L::Tail>::result;
};
template<>
struct Lenght<NullType> {
	static const int result = 0;
};

/* Get index of type T in L */
template <typename TL, typename S>
struct IndexOf;
template <typename Tail, typename S>
struct IndexOf<TypeList<S, Tail>, S> {
	static const int result = 0;
};
template <typename S>
struct IndexOf<NullType, S> {
	static const int result = -1;
};
template <typename Head, typename Tail, typename S>
struct IndexOf<TypeList<Head, Tail>, S> {
	static const int temp = IndexOf<Tail, S>::result;
	static const int result = (temp==-1 ? -1 : temp+1);
};

/* Concatenation of L1 and L2 */
template <typename L1, typename L2>
struct Concatenation;
template <typename Head, typename Tail, typename L2>
struct Concatenation<TypeList<Head, Tail>, L2>{
	typedef TypeList<Head, typename Concatenation<Tail, L2>::Result> Result;
};
template <typename L2>
struct Concatenation<NullType, L2> {
	typedef L2 Result;
};
template <typename L1>
struct Concatenation<L1, NullType> {
	typedef L1 Result;
};

/* Remove duplicates */
// TODO
// template <typename L>
// struct Duplicates;
// template <typename Head, typename Tail>
// struct Duplicates<TypeList<Head, Tail>> {
// 	typedef TypeList<Head, Duplicates<Tail>> Result;
// };


/*
			Main
*/
typedef TypeList<char, NullType> Lchar;
typedef TypeList<int, NullType> Lint;
typedef TypeList<int, TypeList<char, NullType>> Lint_char;

int main() {

	TypeAt<Lint_char, 0>::Result int_var = 65;
	TypeAt<Lint_char, 1>::Result char_var = 65;
	std::cout << int_var << " " << char_var << std::endl;

	std::cout << IndexOf<Lint_char, char>::result
			<< " "
			<< IndexOf<Lint_char, int>::result
			<< " "
			<< IndexOf<Lint_char, int*>::result
			<< std::endl;

	TypeAt<Concatenation<Lchar, Lint>::Result,0>::Result char_var2 = 65;
	std::cout << char_var2 << std::endl;
}