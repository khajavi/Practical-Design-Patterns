#include <iostream>
using namespace std;

class DocumentGenerator {
protected:
	virtual void generateHeader() = 0;
	virtual void generateBody() = 0;
	virtual void generateDetails() = 0;
public:
	void generateDocument() {
		generateHeader();
		generateBody();
		generateDetails();
	}
};

class HtmlGenerator : public DocumentGenerator {
protected:
	virtual void generateHeader() {
		cout << "Header of HTML Document is created" << endl;
	}
	
	virtual void generateBody() {
		cout << "Body of HTML Document is created" << endl;
	}

	virtual void generateDetails() {
		cout << "Details of HTML Document is created" << endl;
	}
};


class PDFGenerator : public DocumentGenerator {
protected:
	virtual void generateHeader() {
		cout << "Header of PDF Document is created" << endl;
	}
	
	virtual void generateBody() {
		cout << "Body of PDF Document is created" << endl;
	}

	virtual void generateDetails() {
		cout << "Details of PDF Document is created" << endl;
	}
};


int main (int argc, char const* argv[]) {
	
	DocumentGenerator* generator;

	generator = new PDFGenerator();
	generator->generateDocument();

	generator = new HtmlGenerator();
	generator->generateDocument();

	return 0;
}

