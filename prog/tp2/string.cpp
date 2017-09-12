#include <iostream>
#include <cstring>

#define UNIT_TEST 1


class TestStr{
public:
	TestStr(){
		if(!UNIT_TEST)
			return;
		std::cout << test_str_default_constructor() << " : test_str_default_constructor" << std::endl;
		std::cout << test_str_cstring_constructor() << " : test_str_cstring_constructor" << std::endl;
		std::cout << test_str_char_constructor() << " : test_str_char_constructor" << std::endl;
		std::cout << test_str_to_string_constructor() << " : test_str_to_string_constructor" << std::endl;
		std::cout << test_str_op_concat_constructor() << " : test_str_op_concat_constructor" << std::endl;
		std::cout << test_str_op_bool_constructor() << " : test_str_op_bool_constructor" << std::endl;
	}
private:
	bool test_str_default_constructor();
	bool test_str_cstring_constructor();
	bool test_str_char_constructor();
	bool test_str_to_string_constructor();
	bool test_str_op_concat_constructor();
	bool test_str_op_bool_constructor();

};

class Str{
public:
	/* new char[1] */
	Str() : size(0), elements((char*) malloc(sizeof(char))){
		/* Size without last 0. Index on the last 0. */
		elements[0] = '\0';
	}

	Str(const char* s) : size(0), elements((char*) malloc(sizeof(char))){
		append(s);
	}

	Str(const char c) : size(0), elements((char*) malloc(sizeof(char))){
		char s[2];
		s[0] = c;
		s[1] = '\0';
		append(s);
	}

	~Str(){
		if(elements != NULL)
			free(elements);
	}

	const char * to_string(){
		return elements;
	}

	void append(const char * s){
		if(strcmp(s, "") == 0)
			return;
		grow(strlen(s));
		for (int i=0; i < strlen(s); i++){
			elements[size] = s[i];
			size++;
		}
		elements[size] = '\0';
	}

	Str & operator+(const & Str s){
		append(s.elements);
		return *this;
	}
	bool operator!=(const & Str s){
		return strcmp(elements, s.elements) != 0;
	}
	bool operator==(const & Str s){
		return strcmp(elements, s.elements) == 0;
	}
	bool operator<(const & Str s){
		return strcmp(elements, s.elements) < 0;	
	}
	bool operator>(const & Str s){
		return strcmp(elements, s.elements) > 0;	
	}
	bool operator<=(const & Str s){
		return strcmp(elements, s.elements) <= 0;	
	}
	bool operator>=(const & Str s){
		return strcmp(elements, s.elements) >= 0;	
	}

	int length(){
		return size;
	}

	friend TestStr;
private:
	void grow(int size){
		elements = (char*) realloc(elements, size + size);
	}

	int size;
	char *elements;
};



bool TestStr::test_str_default_constructor(){
	Str s;
	if(s.size != 0)
		return false;
	if(s.elements[0] != '\0')
		return false;

	return true;
	
}

bool TestStr::test_str_cstring_constructor(){
	char cstring[] = "Vive les cours de c++";
	Str s(cstring);
	if(s.size != strlen(cstring))
		return false;
	if(strcmp(s.elements, cstring) != 0)
		return false;

	return true;
	
}

bool TestStr::test_str_char_constructor(){
	Str s('u');
	if(s.size != 1)
		return false;
	if(strcmp(s.elements, "u") != 0)
		return false;

	return true;
}

bool TestStr::test_str_to_string_constructor(){
	char cstring[] = "Vive le pthon aussi !";
	Str s(cstring);
	if(strcmp(cstring, s.to_string()) != 0)
		return false;

	char cstring_vide[] = "";
	Str s_vide(cstring_vide);
	if(strcmp(cstring_vide, s_vide.to_string()) != 0)
		return false;

	return true;
}

bool TestStr::test_str_op_concat_constructor(){
	char debut[] = "Mais surtout...";
	char fin[] = " Vive le C++ !";
	char concat[30];
	strcat(concat, debut);
	strcat(concat, fin);

	Str s(debut);
	Str s(fin);

}

bool TestStr::test_str_op_bool_constructor(){
	char ch1[] = "Le Python c'est plutot bien quand même.";
	char ch2[] = "Voire franchement super bien !";
	
}



int main(int argc, char const *argv[])
{
	TestStr testStr;

	return 0;
}