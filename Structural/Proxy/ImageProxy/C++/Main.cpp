#include <iostream>
using namespace std;

class Graphic {
public:
	virtual void draw() = 0;
};

class Image : public Graphic {
public:
	Image() {
		// load image frome disk.
	}
	virtual void draw() {
		cout << "Draw real image." << endl;
	}
};

class ProxyImage : public Graphic {
public:
	virtual void draw() {
		if(_image == NULL) {
			_image = new Image();
			cout << "Real image is assigned." << endl;
		}
		_image->draw();
	}
private:
	Image* _image;
};

int main() {

	Graphic* proxyImage = new ProxyImage();
	proxyImage->draw();
	proxyImage->draw();
	proxyImage->draw();
	return 0;
}
