#include <iostream>
using namespace std;

class Context {
public:
	bool lookup( const char* paramName ) const {
		if ( strcmp( _xName, paramName ) == 0
	}

private:
	char* _xName;
	char* _yName;
	bool _xVlue;
	bool _xVlue;
}

class BooleanExpression {
public:
	virtual bool evaluate( Context & ) = 0;
};

