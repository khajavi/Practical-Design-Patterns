#include <iostream>

class Prototype {
	public:
		virtual ~Prototype() { }
		virtual Prototype* clone() const = 0;
};

class ConcreatePrototype: public Prototype {
	public:
		ConcreatePrototype(int x)
			:x_(x) {
			}
		ConcreatePrototype(const ConcreatePrototype& p)
			:x_(p.x_) {
			}
		virtual Prototype* clone() const {
			return new ConcreatePrototype(*this);
		}

		void setX(int x) {
			x_ = x;
		}

		int getX() const {
			return x_;
		}

		void printX() const {
			std::cout << "Value :" << x_ << std::endl;
		}
	private:
		int x_;
};


int main() {

	Prototype* prototype  = new ConcreatePrototype(1000);
	for (int i = 1; i < 100; i++) {
		ConcreatePrototype* tempotype = 
			dynamic_cast<ConcreatePrototype*>(prototype->clone());
		tempotype->setX(tempotype->getX() * i);
		tempotype->printX();
	}

	return 0;

}
