<div dir="rtl">
# هدف
اعمالی که باید روی عناصری از شیء اجرا شود را ارائه می‌کند. این الگو اجازه را می‌دهد تا اعمال جدیدی تعریف کنید بدون اینکه کلاس‌هایی که این اعمال روی آن‌ها انجام می‌شود را تغییر دهید.

# ساختار
![Visitor Pattern](http://www.dofactory.com/Patterns/Diagrams/visitor.gif)

# نکات طراحی

# مثال
فرض کنید سلسله مراتبی از ساختار حیوانات به صورت زیر داشته باشیم:
<div dir="ltr">
```c++
class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };
```
<div dir="rtl">
فرض کنید بخواهیم که عملیات جدیدی برای این سلسله مراتب تعیین کنیم تا هر حیوان صدای مخصوص به خود را ایجاد کند. با استفاده از پلی‌مورفیزم این کار را انجام می‌دهیم.
<div dir="ltr">
```c++
class Animal {
public: virtual void makeSound() = 0;
};

class Dog : public Animal {
public: viod makeSound { cout << "woof!" << endl }
};

class Cat : public Animal {
public: void makeSound { cout << "meow!" << endl; }
};
```
<div dir="rtl">
با این روش هر بار که بخواهیم رفتار جدیدی به این ساختار سلسله مراتبی اضافه کنیم مجبوریم هر یک از کلاس‌ها را تک تک تغییر دهیم. به کمک الگوی ویزیتور می‌توانیم از این ضعف طراحی جلوگیری کنیم:
<div dir="ltr">
```c++
class Operation;

class Animal {
public:
	virtual void letsDo( Operation* op ) = 0;
};

class Cat;
class Dog;

class Operation {
public:
	virtual void catOperation( Cat* cat ) = 0;
	virtual void dogOperation( Dog* dog ) = 0;
};

class Sound : public Operation {
public:
	void dogOperation(Dog* dog ) {
		cout << "woof!" << endl;
	}

	void catOperation(Cat* cat ) {
		cout << "meow!" << endl;
	}
};

class Dog : public Animal {
public:
	void letsDo( Operation* op ) {
		op->dogOperation( this );
	}
};

class Cat : public Animal {
public:
	void letsDo( Operation* op ) {
		op->catOperation( this );
	}
};

int main() {

	Cat* cat = new Cat();
	Sound* sound = new Sound();
	cat->letsDo( sound );

	return 0;
}
```
<div dir="rtl">

# مثال‌های واقعی
<div dir="ltr">
- javax.lang.model.element.AnnotationValue and AnnotationValueVisitor
- javax.lang.model.element.Element and ElementVisitor
- javax.lang.model.type.TypeMirror and TypeVisitor
