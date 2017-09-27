#include <iostream>
#include <deque>
#include <algorithm>    // std::generate

class MultipleGenerator{
protected:
	int multiple;
	int compteur;
public:
	MultipleGenerator(int const & _multiple) : multiple(_multiple), compteur(0) {}

	int operator ()(){
		return multiple * (compteur++);
	}
};


template<typename T>
void ostream_iterator (std::ostream const & stream, T const & o){
	T* it = o.begin();
	while(it != o.end()){
		stream << *it++ << " ";
	}
	stream << std::endl;
}

int main(){
	/* Exercice 1 */
	std::deque<int> d = std::deque<int>(5);

  	std::generate(d.begin(), d.end(), MultipleGenerator(4));

  	ostream_iterator<std::deque<int>>(std::cout, d);

  	std::set s1(d);

  	d.empty();

  	std::set s2;
  	MultipleGenerator mg(2);
  	for (int i = 0; i < 10; i++){
  		s2.push_front(mg());
  	}

  	std::set s3;
  	return 0;
}