#include <iostream>
#include <cstring>

#define UNIT_TEST 1

/***********************************************
				swap
***********************************************/

template <typename T>
void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

bool test_swap(){
	int a = 3;
	int b = 4;
	swap<int>(a, b);
	if(a != 4)
		return false;
	if(b != 3)
		return false;

	return true;
}

/***********************************************
				min
***********************************************/

template <typename T>
T min(T const & a, T const & b){
	if(a<b)
		return a;
	return b;
}

/* !!! char * différent de char[]b */
template<const char*>
char *min(const char *a, const char *b){
	if(strcmp(a,b)<0)
		return a;
	return b;
}

bool test_min(){
	bool result = true;
	char const *s1 = "coucou";
	char const *s2 = "wahou";
	char *hards1 = (char*)malloc(7);
	strcpy(hards1, "coucou");
	char *hards2 = (char*)malloc(7);
	strcpy(hards2, "woucou");
	
	if(min<double>(-4, 7) != -4)
		result = false;
	else if(min<std::string>("coucou", "whaou") != "coucou")
		result = false;
	else if(strcmp(min<const char*>(s1, s2), s1) != 0)
		result = false;
	else if(strcmp(min<const char*>(s2, s1), s1) != 0)
		result = false;
	else if(min(hards1, hards2) != hards1)
		result = false;
	else if(min(hards2, hards1) != hards1)
		result = false;

	free(hards1);
	free(hards2);
	return result;
}

/***********************************************
				Tableau
***********************************************/

bool test_tableau();

template<typename T, int SIZE>
class Tableau{
protected:
	T *elements;
	int total_size;
	int index;

	void grow(){
		total_size += SIZE;
		elements = (T*)realloc(elements, total_size);
	}

public:
	Tableau():elements((T*)malloc(0)), total_size(0), index(0) {}
	Tableau(Tableau<T, SIZE> const & t):elements((T*)malloc(t.total_size)), total_size(t.total_size), index(t.index) {
		memcpy(elements, t.elements, index);
	}
	/* _size is the element number in the table */
	Tableau(const T tableau[], const int _size):elements(malloc(0)), total_size(0), index(0) {
		for (int i = 0; i < _size; i){
			push(tableau[i]);
		}
	}
	~Tableau(){
		free(elements);
	}

	void push(T const & element){
		if(index == total_size)
			grow();
		elements[index++] = element;
	}

	int size(){
		return index;
	}

	T & operator[](const int i){
		if(i>=index)
			std::cout << "Index out of bounds " << i << std::endl;
		return elements[i];
	}

	void operator=(const Tableau t){
		free(elements);
		total_size = t.total_size;
		index = t.index;
		elements = (T*)malloc(t.total_size);
		for (int i = 0; i < t.index; i++){
			elements[i] = t.elements[i];
		}
	}

friend bool test_tableau();
};

bool test_tableau(){
	// Tableau<int, 10> tint(); -> créé une fonction tint
	Tableau<int, 10> tint;
	if(tint.total_size != 0)
		return false;
	if(tint.index != 0)
		return false;

	tint.push(3);
	if(tint.index != 1)
		return false;
	if(tint.elements[0] != 3)
		return false;
	if(tint.total_size != 10)
		return false;

	Tableau<int, 10> tint2(tint);
	if(tint.index != 1)
		return false;
	if(tint.elements[0] != 3)
		return false;
	if(tint.total_size != 10)
		return false;
	tint2.push(3);
	if(tint.index != 1)
		return false;

	if(tint[0] != 3)
		return false;

	Tableau<int, 10> tint3 = tint;
	if(tint3.index != 1)
		return false;
	if(tint3.elements[0] != 3)
		return false;
	if(tint3.total_size != 10)
		return false;

	return true;
}

/***********************************************
				main
***********************************************/

int main(int argc, char const *argv[])
{
	std::cout << "Test order matters" << std::endl;
	std::cout << test_swap() << " : test_swap" << std::endl;
	std::cout << test_min() << " : test_min" << std::endl;
	std::cout << test_tableau() << " : test_tableau" << std::endl;
	return 0;
}