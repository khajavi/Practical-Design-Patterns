/*
 * Adopted from http://advancedcppwithexamples.blogspot.de/2010/10/c-example-of-flyweight-design-pattern.html
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Character {
public:
	Character( const char ch, int width, int height, int ascent, int descent, int pointSize  )
		:_symbol( ch ),
		_width( width ),
		_height( height ),
		_ascent( ascent ),
		_descent( descent ),
		_pointSize( pointSize ) {
	}

	virtual void display( int pointSize ) = 0;
protected:
	char _symbol;
	int _width;
	int _height;
	int _ascent;
	int _descent;
	int _pointSize;
};

class CharacterA : public Character {
public:
	CharacterA()
		:Character( 'A', 120, 100, 70, 0, 0) {
	}

	void display( int pointSize ) {
		_pointSize = pointSize;
		cout << _symbol << " (pointSize " << _pointSize << " )" << endl;
	}
};

class CharacterB : public Character {
public:
	CharacterB()
		:Character( 'B', 140, 100, 72, 0, 0 ) {
	}

	void display( int pointSize ) {
		_pointSize = pointSize;
		cout << _symbol << " (pointSize " << _pointSize << " )" << endl;
	}
};

class CharacterZ : public Character {
public:
	CharacterZ()
		:Character( 'Z', 100, 100, 68, 0, 0 ) {
	}

	void display( int pointSize ) {
		_pointSize = pointSize;
		cout << _symbol << " (pointSize " << _pointSize << " )" << endl;
	}
};

class CharacterFctory {
public:
	Character* geCharacter( char key ) {
		Character* character = NULL;
		if ( _characters.find( key ) != _characters.end() ) {
			character = _characters[key];
		} else {
			switch ( key ) {
				case 'A':
					character = new CharacterA();
					break;
				case 'B':
					character = new CharacterB();
					break;
				case 'Z':
					character = new CharacterZ();
					break;
				default:
					cout << "Not Implemented Yet" << endl;
					throw ( "Not Implemented" );
			}
			_characters[ key ] = character;
		}
		return character;
	}

private:
	map< char, Character* > _characters;
};

int main() {

	string document = "AAZZBBZB";
	const char* chars = document.c_str();
	
	CharacterFctory* factory = new CharacterFctory();
	
	int pointSize = 10;

	for ( size_t i = 0; i < document.length(); i++ ) {
		pointSize++;
		Character* character = factory->geCharacter( chars[ i ] );
		character->display( pointSize );
	}

	return 0;
}
