#include <iostream>
#include <deque>
#include <algorithm>    // std::generate

int generator_index = 0;
int generator(){
	return 4 * (++generator_index);
}

template<typename T>
void ostream_iterator (std::ostream const & stream, T const & o){
	o::iterator it = o.begin();
	while(it != o.end()){
		stream << *it++ << " ";
	}
	stream << std::endl;
}

int main(){
	/* Exercice 1 */
	std::deque<int> d = std::deque<int>(5);

  	std::generate(d.begin(), d.end(), generator);

  	ostream_iterator<std::deque<int>> oit(std::cout, d);


  	return 0;
}