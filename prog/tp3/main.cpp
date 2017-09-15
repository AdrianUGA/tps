#include <iostream>

#define UNIT_TEST 1

class TestExpressions{
public:
	TestExpressions(){
		if(!UNIT_TEST)
			return;
		std::cout << std::endl << "TestExpressions" << std::endl;
		std::cout << constante_constuct() << " : constante_constuct" << std::endl;
		std::cout << constante_value() << " : constante_value" << std::endl;
		std::cout << plus() << " : plus" << std::endl;

	}

private:
	bool constante_constuct();
	bool constante_value();

	bool plus();
};

/***********************************
			Expressions
***********************************/

class Expression{
public:
	Expression(){}
	~Expression(){}
	virtual double eval() const =0;
	virtual Expression * clone() const;
};

class Constante: public Expression{
public:
	Constante(double _x):Expression(), x(_x){}

	double eval() const{
		return x;
	}

	Expression * clone() const {
		return new Constante(x);
	}

	friend TestExpressions;
protected:
	double x;
};

class 

ExpressionBinaire: public Expression{
public:
	ExpressionBinaire(Expression const & _left, Expression const & _right):Expression(), left(_left.clone()), right(_right.clone()) {}
	~ExpressionBinaire(){
		free(left, right);
	}
protected:
	Expression const * left;
	Expression const * right;
};

class Plus: public ExpressionBinaire{
public:
	Plus (Expression const & _left, Expression const & _right) : ExpressionBinaire( _left,  _right) {}

	double eval() const{
		return left->eval() + right->eval();
	}

	Expression * clone() const {
		return new Plus(left, right);
	}
};

class Moins: public ExpressionBinaire{
public:
	Moins (Expression const & _left, Expression const & _right) : ExpressionBinaire( _left,  _right) {}

	double eval() const{
		return left->eval() - right->eval();
	}

	Expression * clone() const {
		return new Moins(left, right);
	}
};

class Mult: public ExpressionBinaire{
public:
	Mult (Expression const & _left, Expression const & _right) : ExpressionBinaire( _left,  _right) {}

	double eval() const{
		return left->eval() * right->eval();
	}

	Mult * clone() const {
		return new Plus(left, right);
	}
};


/***********************************
			Tests
***********************************/

bool TestExpressions::constante_constuct(){
	Constante c(10.2);
	if(c.x != 10.2)
		return false;
	return true;
}
bool TestExpressions::constante_value(){
	Expression const & e = Constante(3.1);
	if(e.eval() != 3.1)
		return false;
	return true;
}
bool TestExpressions::plus(){
	Expression const & e = Plus(Constante(3.1), Constante(3.1));
	if(e.eval() != 6.2)
		return false;
	return true;
}






int main() {
	TestExpressions t;

	int a=5;
	
	const Expression & e = Mult(
		Plus(Constante(a), Constante(-2)),
		Plus(Constante(1),Constante(3))
	);
	std::cout << e.eval() << std::endl;
	return 0;
}