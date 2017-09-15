#include <iostream>

#define UNIT_TEST 1


class IntegerFactoryTest{
public:
	IntegerFactoryTest(){
		if(!UNIT_TEST)
			return;
		std::cout << "IntegerFactoryTest" << std::endl;
		std::cout << testConstructor() << " : testConstructor" << std::endl;
		std::cout << testGet() << " : testGet" << std::endl;
	}
private:
	bool testConstructor();
	bool testGet();
};

class IntegerFactory{

public:
	IntegerFactory(int n=5): multiple(n), current_value(0){}

	int get_next(){
		return current_value += multiple;
	}
	
	friend IntegerFactoryTest;
private:
	int multiple;
	int current_value;
};


bool IntegerFactoryTest::testConstructor(){
	IntegerFactory f;
	IntegerFactory f2(2);
	if(f2.multiple != 2)
		return false;
	if(f.multiple != 5)
		return false;
	if(f.current_value != 0)
		return false;
	return true;
}

bool IntegerFactoryTest::testGet(){
	IntegerFactory f(5);
	for (int i = 1; i < 1000; i++)
	{
		if(i*5 != f.get_next())
			return false;

	}
	return true;
}

int main(int argc, char const *argv[])
{
	IntegerFactoryTest integerFactoryTest;

	return 0;
}