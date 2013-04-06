<div dir="rtl">
# هدف
لایهٔ انتزاع را از لایهٔ پیاده‌سازی جدا می‌کند، بنابراین دو کلاس می‌توانند مستقلاً تغییر کنند.

# ساختار
![Bridge UML](http://javaobsession.files.wordpress.com/2010/07/bridge-pattern1.png)

# اجزاء
- Abstraction
- RefinedAbstraction
- Implementor
- ConcreteImplementor

# نکات طراحی
از این الگو زمانی استفاده کنید که
- لایهٔ انتراع و پیاده‌سازی نباید در زمان اجرا به هم وابسته باشند.
- لایهٔ انتزاع و پیاده‌سازی باید مستقلاً قابل گسترش و توسعه باشند.
- جزئیات لایهٔ پیاده‌سازی باید از دیدگاه کارخواه مخفی بماند.
- تغییرات در لایهٔ پیاده‌سازی (که لایهٔ انتزاع را پیاده‌سازی می‌کند) نباید منجر به کامپایل مجدد کدِ کارخواه شود.

برای طراحی این الگو، در کلاس انتزاعی، یک نمونه از کلاس پیاده‌سازی نگه می‌داریم. در این صورت قادر خواهیم بود که در زمان اجرا، پیاده‌سازی‌های متفاوتی را برای کلاس انتزاعی در نظر بگیریم. به کد زیر توجه کنید:
<div dir="ltr">
```java
Implementation implementation = new FirstImplementation();
Abstraction abstraction = new Abstraction( implementation );
abstraction.operation();
```
<div dir="rtl">
# مثال
فرض کنید که می‌خواهیم کلاس قطارها را طراحی کنیم. دو نوع قطار داریم. قطارهای معمولی و قطارهای یک ریلی.
<div dir="ltr">
```c++
class Train {
public: 
	virtual void move() = 0;
};

class MonoRail : public Train {
public:
	virual void move() { /* use one track */ }
};

class Rail : public Train {
public:
	virtual void move() { /* use twi track */ }
};
```
<div dir="rtl">
فرض کنید بعد از پیاده‌سازی دو قطار بالا به قطارهای برقی هم نیاز پیدا کنیم. آنگاه مجبوریم کلاس‌ها را به شکل زیر تغییر دهیم:
<div dir="ltr">
```c++
class Train {
public:
  virtual void move() = 0;
};

class MonoRail : public Train {
public:
  virtual void move() { /* use one track */ }
};

class ElectronicMonoRail : public MonoRail {
public:
  virtual void move() { /* electronic engine on one track */ }
};

class DiselMonoRail : public MonoRail {
public:
  virtual void move() { /* disel engine on one track */ }
};

class Rail {
public:
  virtual void move() { /* use two tracks */ }
};

class ElectricRail : public Rail {
  virtual void move() { /*  use electric engine on two tracks */ }
};

class DiselRail : public Rail {
  virtual void move() { /*  use disel engine on two tracks */ }
};
```
<div dir="rtl">
کد بالا قابل نگهداری نیست و فاقد قابلیت استفادهٔ مجدد است. کد زیر الگوی Bridge را به کد بالا اعمال می‌کند و دو لایهٔ انتزاع `train transport` و `acceleration` را از هم جدا می‌کند.
<div dir="ltr">
```c++
class Train {
public:
  virtual void move( Accelerable* engine ) = 0;
};

class Accelerable {
public:
  virtual void acclerate();
};

class MonoRail : public Train {
public:
  virtual void move( Accelerable* engine ) {
    engine->acclerate(); //engine is pluggable (runtime dynamic)
  }
};

class Rail : public Train {
public:
  virtual void move( Accelerable* engine ) {
    engine->acclerate(); // engine is pluggable (runtime dynamic)
  }
};

class ElectricEngine : public Accelerable { }
class DiselEngine : public Accelerable{ }
```
