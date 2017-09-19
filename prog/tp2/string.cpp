#include <iostream>
#include <cstring>

#define UNIT_TEST 1


class TestStr{
public:
	TestStr(){
		if(!UNIT_TEST)
			return;
		std::cout << "Test order matters !" << std::endl;
		std::cout << test_str_default_constructor() << " : test_str_default_constructor" << std::endl;
		std::cout << test_str_cstring_constructor() << " : test_str_cstring_constructor" << std::endl;
		std::cout << test_str_char_constructor() << " : test_str_char_constructor" << std::endl;
		std::cout << test_str_cstring() << " : test_str_cstring" << std::endl;
		std::cout << test_str_op_concat() << " : test_str_op_concat" << std::endl;
		std::cout << test_str_op_bool() << " : test_str_op_bool" << std::endl;
		std::cout << test_str_substr() << " : test_str_substr" << std::endl;
		std::cout << test_str_streams() << " : test_str_streams" << std::endl;
		std::cout << test_str_square_brakets() << " : test_str_square_brakets" << std::endl;
		std::cout << test_str_constructor_substring() << " : test_str_constructor_substring" << std::endl;
	}
private:
	bool test_str_default_constructor();
	bool test_str_cstring_constructor();
	bool test_str_char_constructor();
	bool test_str_cstring();
	bool test_str_op_concat();
	bool test_str_op_bool();
	bool test_str_substr();
	bool test_str_streams();
	bool test_str_square_brakets();
	bool test_str_constructor_substring();

};

class Str{
public:
	/* new char[1] */
	Str() : size(0), elements((char*) malloc(sizeof(char))){
		init();
	}

	Str(const char* s) : size(0), elements((char*) malloc(sizeof(char))){
		init();
		append(s);
	}

	Str(const std::string s) : size(0), elements((char*) malloc(sizeof(char))){
		init();
		append(s);
	}

	Str(const char c) : size(0), elements((char*) malloc(sizeof(char))){
		init();
		char s[2];
		s[0] = c;
		s[1] = '\0';
		append(s);
	}

	Str(const char *s, const char *substr_to_remove) : size(0), elements((char*) malloc(sizeof(char))){
		init();
		int substr_len = strlen(substr_to_remove);
		int s_len = strlen(s);
		for (int i = 0; i < s_len; i++){
			bool substr_here = false;
			if(i+substr_len < s_len){
				substr_here = true;
				for (int j = 0; j < substr_len; j++){
					if(s[i+j] != substr_to_remove[j]){
						substr_here = false;
						break;
					}
				}
			}
			if(substr_here)
				i += substr_len - 1;
			else
				append(Str(s[i]).cstring());
		}

	}

	~Str(){
		if(elements != NULL)
			free(elements);
	}

	const char * cstring(){
		return elements;
	}

	void append(const char * s){
		if(strcmp(s, "") == 0)
			return;
		grow(strlen(s));
		strcat(elements, s);
		// for (int i=0; i < strlen(s); i++){
		// 	elements[size] = s[i];
		// 	size++;
		// }
		// elements[size] = '\0';
	}

	void append(const std::string s){
		append(s.c_str());
	}

	Str & operator+(Str const & s){
		append(s.elements);
		return *this;
	}
	
	bool operator!=(Str const & s){
		return strcmp(elements, s.elements) != 0;
	}
	bool operator==(Str const & s){
		return strcmp(elements, s.elements) == 0;
	}
	bool operator<(Str const & s){
		return strcmp(elements, s.elements) < 0;	
	}
	bool operator>(Str const & s){
		return strcmp(elements, s.elements) > 0;	
	}
	bool operator<=(Str const & s){
		return strcmp(elements, s.elements) <= 0;	
	}
	bool operator>=(Str const & s){
		return strcmp(elements, s.elements) >= 0;	
	}
	char & operator[](int i){
		return elements[i];
	}

	bool empty(){
		return size == 0;
	}

	int length(){
		return size;
	}

	Str substr(int begin, int end){
		Str s("");
		for (int i = begin; i < end && i < size; i++) {
			s + Str(elements[i]);
		}
		return s;
	}

	friend TestStr;
	friend std::istream & operator>>(std::istream &is, Str &s);
	friend std::ostream & operator<<(std::ostream &os, Str &s);
private:
	void init(){
		elements[0] = '\0';
	}
	void grow(int n){
		size += n;
		elements = (char*) realloc(elements, size);
	}

	int size; /* Size without last 0. Index on the last 0. */
	char *elements;
};

std::istream & operator>>(std::istream &is, Str &s){
	is >> s.elements;
	return is;
}

std::ostream & operator<<(std::ostream &os, Str &s){
	os << s.elements;
	return os;
}


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

bool TestStr::test_str_cstring(){
	char cstring[] = "Vive le pthon aussi !";
	Str s(cstring);
	if(strcmp(cstring, s.cstring()) != 0)
		return false;

	char cstring_vide[] = "";
	Str s_vide(cstring_vide);
	if(strcmp(cstring_vide, s_vide.cstring()) != 0)
		return false;

	return true;
}

bool TestStr::test_str_op_concat(){
	char debut[] = "Mais surtout...";
	char fin[] = " Vive le C++ !";
	char concat[30]; concat[0] = '\0';
	strcat(concat, debut);
	strcat(concat, fin);

	Str sdeb(debut);
	Str sfin(fin);

	if(strcmp((sdeb + sfin).elements, concat) != 0)
		return false;
	return true;
}

bool TestStr::test_str_op_bool(){
	char ch1[] = "Le Python c'est plutot bien quand même.";
	char ch2[] = "Voire franchement super bien !";
	Str s1(ch1);
	Str s2(ch2);
	if(s1 != s1)
		return false;
	if(s1 == s2)
		return false;
	if(s1 > s2)
		return false;
	if(s2 < s1)
		return false;
	if(s1 >= s2)
		return false;
	if(s2 <= s1)
		return false;
	if(s1 < s1)
		return false;
	if(s1 > s1)
		return false;
	return true;
}

bool TestStr::test_str_square_brakets(){
	char str[] = "Hello !";
	Str s(str);
	for (int i = 0; i < strlen(str); ++i)
	{
		if(s[i] != str[i])
			return false;
	}
	// todo
	s[0] = 'W';
	if(s[0] != 'W')
		return false;
	return true;
}

bool TestStr::test_str_substr(){
	Str s("This is a substring");
	if(strcmp(s.substr(10,19).elements, "substring") != 0)
		return false;
	if(strcmp(s.substr(10,200).elements, "substring") != 0)
		return false;
	if(strcmp(s.substr(20,1).elements, "") != 0)
		return false;
	return true;
}

bool TestStr::test_str_streams(){
	std::string s1("Coucou");
	Str s2("Coucou");
	s1.append(" toi !");
	s2.append(" toi !");
	Str s3(s1.c_str());
	if(s2 != s3)
		return false;
	return true;
}

bool TestStr::test_str_constructor_substring(){
	Str s("Coucou gercoutrude", "cou");
	if(strcmp(s.cstring(), "Cou gertrude") != 0)
		return false;
	return true;
}



int main(int argc, char const *argv[]) {
	TestStr testStr;
	return 0;
}