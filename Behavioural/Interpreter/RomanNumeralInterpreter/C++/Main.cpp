/*
 * Adopted from http://sourcemaking.com/design_patterns/interpreter/cpp/1
 */

#include <iostream>
#include <string.h>
using namespace std;

class Thousand;
class Hundred;
class Ten;
class One;

class RomanNumeralInterpreter {
public:
	RomanNumeralInterpreter();
	RomanNumeralInterpreter( int ) {}

	int interpret( char* );  // interpret for client
	virtual void interpret( char* input, int &total ) { 
		int index;
		index = 0;
		if ( !strncmp( input, nine(), 2 ) ) {
			total += 9 * multiplier();
			index += 2;
		} else if ( !strncmp( input, four(), 2 ) ) {
			total += 4 * multiplier();
			index += 2;
		} else {
			if ( input[0] == five() ) {
				total += 5 * multiplier();
				index = 1;
			}
			else {
				index = 0;
			}
			
			for ( int end = index + 3; index < end; index++ ) {
				if ( input[index] == one() )
					total += 1 * multiplier();
				else 
					break;
			}
		}
		strcpy( input, &(input[index]) );
	}
protected:
	// Cannot be pure virtual fuction, because client asks for instance
	virtual const char one() {}
	virtual const char* four() {}
	virtual const char five() {}
	virtual const char* nine() {}

	virtual int multiplier() {}
private:
	RomanNumeralInterpreter* thousands;
	RomanNumeralInterpreter* hundreds;
	RomanNumeralInterpreter* tens;
	RomanNumeralInterpreter* ones;
};

class Thousand : public RomanNumeralInterpreter {
public:
	Thousand( int ) : RomanNumeralInterpreter( 1 ) {}
protected:
	const char one() {
		return 'M';
	}
	
	const char* four() {
		return "";
	}

	const char five() {
		return '\0';
	}

	const char* nine() {
		return "";
	}

	int multiplier() {
		return 1000;
	}
};

class Hundred : public RomanNumeralInterpreter {
public:
	Hundred( int ) : RomanNumeralInterpreter( 1 ) {}
protected:
	const char one() {
		return 'c';
	}

	const char* four() {
		return "CD";
	}

	const char five() {
		return 'D';
	}

	const char* nine() {
		return "CM";
	}

	int multiplier() {
		return 100;
	}
};

class Ten : public RomanNumeralInterpreter {
public:
	Ten( int ) : RomanNumeralInterpreter( 1 ) {}
protected:
	const char one() {
		return 'X';
	}
	
	const char* four() {
		return "XL";
	}

	const char five() {
		return 'L';
	}

	const char* nine() {
		return "XC";
	}

	int multiplier() {
		return 10;
	}
};

class One : public RomanNumeralInterpreter {
public:
	One( int ) : RomanNumeralInterpreter( 1 ) {}
protected:
	const char one() {
		return 'I';
	}

	const char* four() {
		return "IV";
	}

	const char five() {
		return 'V';
	}

	const char* nine() {
		return "IX";
	}

	int multiplier() {
		return 1;
	}
};

RomanNumeralInterpreter::RomanNumeralInterpreter() {
	// Use 1-arg ctor to avoid infinite loop
	thousands = new Thousand( 1 );
	hundreds = new Hundred( 1 );
	tens = new Ten( 1 );
	ones = new One( 1 );
}

int RomanNumeralInterpreter::interpret( char* input ) {
	int total;
	total = 0;
	thousands->interpret( input, total );
	hundreds->interpret( input, total );
	tens->interpret( input, total );
	ones->interpret( input, total );

	if ( strcmp( input, "" ) ) //if input was invalid return 0
		return 0;
	
	return total;
}

int main() {
	RomanNumeralInterpreter interpreter;
	char input[20];
	cout << "Enter Roman Numeral: " ;
	while( cin >> input ) {
		cout << "   interpretation is " << interpreter.interpret( input ) << endl;
		cout << "Enter Roman Numeral: ";
	}
}


