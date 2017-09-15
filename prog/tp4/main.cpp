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
T min(T a, T b){
	if(a<b)
		return a;
	return b;
}
template<>
char *min(char *a, char *b){
	if(strcmp(a,b)<0)
		return a;
	return b;
}

bool test_min(){
	if(min<double>(-4, 7) != -4)
		return false;
	if(min<std::string>("coucou", "whaou") != "coucou")
		return false;
	char s1[] = "coucou";
	char s2[] = "wahou";
	if(min<char*>(s1, s2) != s1)
		return false;
	if(min<char*>(s2, s1) != s1)
		return false;

	char *hards1 = (char*)malloc(7);
	strcpy(hards1, "coucou");
	char *hards2 = (char*)malloc(7);
	strcpy(hards2, "woucou");

	if(min(hards1, hards2) != hards1)
		return false;
	if(min(hards2, hards1) != hards1)
		return false;

	return true;
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
		elements = realloc(elements, total_size);
	}

public:
	Tableau():elements(malloc(0)), total_size(0), index(0) {}
	/* _size is the element number in the table */
	Tableau(T tableau[], int _size):elements(malloc(0)), total_size(0), index(0) {
		for (int i = 0; i < _size; i){
			push(tableau[i]);
		}
	}
	~Tableau(){
		free(elements);
	}

	void push(T const & element){
		if(index == size)
			grow();
		elements[index++] = element;
	}

	int size(){
		return index;
	}

friend bool test_tableau();
};

bool test_tableau(){
	Tableau<int, 10> tint();
	if(tint.total_size != 0)
		return false;
	if(tint.index != 0)
		return false;

	return true;
}

/***********************************************
				main
***********************************************/

int main(int argc, char const *argv[])
{
	std::cout << test_swap() << " : test_swap" << std::endl;
	std::cout << test_min() << " : test_min" << std::endl;
	std::cout << test_tableau() << " : test_tableau" << std::endl;
	return 0;
}