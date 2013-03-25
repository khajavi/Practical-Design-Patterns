# الگوهای طراحی Factory
1. Simple Factory (idiom)
2. Factory Method Pattern
3. Abstract Factory

نکات:
1. Factories are used to encapsulate instantiation.
2. Factory Method vs. Abstract Factory: An Abstract Factory is used to create a family of related products (Factory Method creates one product).


## Simple Factory (Idiom)
1. Simple Factory returns instances of classes that have the same methods. They may be instances of different derived subclasses, or they may in fact be unrelated classes that just share the same interface. Either way, the methods in these class instances are the same and can be used interchangeably.
2. Simple Factory یک الگوی طراحی واقعی نیست. اما به عنوان یک idiom برنامه‌نویسی بسیار رایج به کار گرفته می‌شود.
3. وصل کردن کد به کلاس‌های کانکرت، کد را شکننده و غیرقابل انعطاف می‌کند.
4. جایگزینی اپراتور new با متدهای createConcrete
5. می‌توانیم از متد استاتیک در این الگو استفاده کنیم.
6. استفاده از new باعث ایجاد نمونه از کلاس‌های کانکرت می‌شود.
7. استفاده از new یک نوع برنامه‌نویسی مرتبط با پیاده‌سازی‌ست تا یک برنامه‌نویسی مرتبط به اینترفیس. (کد شکننده، خطا پذیر، غیر قابل انعطاف می‌شود)
8. کلاس‌های کانکرت معمولاً بیشتر از یک بار یک مکان نمونه‌برداری (Instantiate) می‌شوند.
9. بنابراین در صورتی که بخواهیم تغییر بدهیم باید تمامی نمونه‌برداری‌ها را در مکان‌های مختلف را تغییر دهیم. که این کار طاقت‌فرسا، سخت و خطاپذیر است.
### چرا از Simple Factory استفاده می‌کنیم؟
1. Multiple Clinets neeeding same types of object
2. Ensure consistent object initialization.

![SimpleFactory](wiki/img/simplefactorystructure.gif)
![Simple Factory](wiki/img/SimpleFactory.jpg)
![Simple Factory Diagram](wiki/img/SimpleFactory.png)

### Keywords:
1. Depenency
2. Loose Couple
3. Concrete classes (When you see `new`, think `concrete`)
4. Encapsulating object creation

### مثال
```java
public class PizzaStore {
	SimplePizzaFactory factory;
 
	public PizzaStore(SimplePizzaFactory factory) { 
		this.factory = factory;
	}
 
	public Pizza orderPizza(String type) {
		Pizza pizza;
 
		pizza = factory.createPizza(type);
 
		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();

		return pizza;
	}

}
```

```java
public class SimplePizzaFactory {

		// می‌توانیم این متود را استاتیک تعریف کنیم تا نیازی به ساخت شیء فکتوری نباشد و بتوانیم مستقیما از کلاس این متود را صدا بزنیم.
	public Pizza createPizza(String type) { 
		Pizza pizza = null;

		if (type.equals("cheese")) {
			pizza = new CheesePizza();
		} else if (type.equals("pepperoni")) {
			pizza = new PepperoniPizza();
		} else if (type.equals("clam")) {
			pizza = new ClamPizza();
		} else if (type.equals("veggie")) {
			pizza = new VeggiePizza();
		}
		return pizza;
	}
}
```
![pizza Simple Factory](http://yuml.me/diagram/scruffy/class/330cfd3a.png)

### اطلاعات بیشتر
1. [Simple Factory Pattern Side by Side with Abstract Pattern](http://www.c-sharpcorner.com/UploadFile/mosessaur/simplefactorypattern03012006124722PM/simplefactorypattern.aspx)
2. [Simple Factory](http://shamsmi.blogspot.fr/2007/08/simple-factory.html)
3. ص ۱۱۹ Head First Design Patterns

## الگوی طراحی Factory Method (Virtual Constructor)
1. The factory method pattern defines an interface for creating an object, but lets subclasses decide which class to instantiate.
2. Factory Method lets a class deffer instantiation to subclasses.
3. Eliminates need to bind creation code to specific subclasses.
4. May need to subclass Creator for each ConcreteProduct
5. Provides hooks for subclasses.
6. Connects parallel class hierarchies.
7. در الگوی طراحی Factory Method از Simple Factory استفاده می‌کنیم.
8. در Simple Factory تنها یک کارخانه داریم. اما اگر چند کارخانه داشته باشیم که همگی این کارخانه‌ها محصولات مشابهی تولید کنند مثلاً همگی موبایل تولید می‌کنند (اما هر کارخانه پیاده‌سازی خودش را دارد) در چنین حالتی از Factory Method استفاده می‌کنیم. به این صورت یک رابط برای کارخانه‌ها ایجاد می‌کنیم و پیاده‌سازی متود ساخت محصول را به کارخانه‌ها واگذار می‌کنیم. هر یک از کارخانه‌ها از Simple Factory برای تولید محصولاتش استفاده می‌کند.
9. به روش بالا می گوییم: Allowing the subclasses to decide یا Real-time decision
10. برای اینکه پارامترهای Concrete Factory بتوانند `Type-Safe` باشند، می‌توانیم از `enum` استفاده کنیم و یا روش‌های بهتر.
11. وقتی که نمونه‌سازی اشیاء را در یک آبجکت یا متد، کپسوله کنیم، باعث بالا رفتن maintenance می‌شود و باعث می‌شود از کدهای اضافی و مجدد خودداری شود.
12. Dependency Inversion Principle.

### ساختار
![Factory Method Pattern](http://yuml.me/f1b5a95b)
![Factory Method](wiki/img/FactoryMethod.jpg)


### مثال ۱- ساخت موبایل از دو کارخانهٔ متفاوت

#### Product (Mobile)
یک واسط برای تمامی موبایل‌ها تعریف می‌کنیم و ویژگی‌ها و رفتارهای مشترک را ذکر می‌کنیم.

1. نام موبایل
2. رنگ

#### ConcreateProduct
واسط موبایل را برای موبایل‌های مختلف پیاده‌سازی می‌کنیم.

1. Nokia N900
2. Nokia N95
3. Motorola Atrix
4. Motorola A1200

#### Creator/Factory
واسط کارخانه
createMobile()

#### ConcreteCreator/ConcreteFactry
هر کدام از کارخانه‌ها باید واسط کارخانه را پیاده‌سازی کنند.

1. NokiaFactory
2. MotorolaFactory
3. ...

#### Client
```
Factory  factory =  new NokiaFactory()
Car car = factory.createMobile(مشخصات موبایل، نام موبایل، مثل رنگ و ...)
```
![Mobile Factory](http://yuml.me/679b958b)
### بیشتر بخوانید
1. کلاس SAXParserFactory
2. http://javapapers.com/design-patterns/factory-method-pattern/
3. http://stackoverflow.com/questions/9963090/factory-pattern-vs-factorymethod-pattern
4. http://c2.com/cgi/wiki?FactoryMethodPattern


## الگوی طراحی Abstract Factory
1. اگر `چند نوع محصول` و چند کارخانهٔ مختلف داشته باشیم از Abstract Factory استفاده می‌کنیم.
2. The job of an `Abstract Factory` is to define an interface for creating `set of products`.

![Abstract Factory](http://yuml.me/9c9bd813)
![Abstract Factory 2](wiki/img/AbstractFactory.jpg)

### مثال

کارخانه‌ها به سه دسته تقسیم می‌شوند (نوکیا/سامسونگ/اچ‌تی‌سی) و محصولات به دو دستهٔ (گوشی‌های هوشمند/گوشی‌های غیرهوشمند)
در این مثال ابتدا یک کلاس انتزاعی از کارخانه‌ها می‌سازیم که این کلاس دو متد دارد، یکی ساخت گوشی هوشمند آن کارخانه و دیگری ساخت گوشی غیرهوشمند آن کارخانه.

سپس از کلاس انتزاعی کارخانه، سه کلاس نوکیا و سامسونگ و اچ‌تی‌سی می‌سازیم که هر کدام از این کارخانه‌ها دو نوع گوشی هوشمند و غیر هوشمند خود را می‌سازند.

در این مثال، کلاینت ما از نام گوشی‌ها با خبر نیست. مثلاً نمی‌داند که گوشی هوشمند سامسونگ چیست. کلاینت درخواستش را اعلام می‌کند. مثلاً می‌گوید گوشی هوشمند سامسونگ را می‌خواهم. کلاس کانکرت کارخانهٔ سامسونگ درون کلاس ساخت گوشی هوشمند خود، گالاکسی‌اس۲ را می‌سازد.

متن کامل مثال: http://www.codeproject.com/Articles/331304/Understanding-and-Implementing-Abstract-Factory-Pa

### بیشتر بخوانید
1. [Simple Factory vs. Factory Method vs. Abstract Factory](http://corey.quickshiftconsulting.com/1/post/2009/5/first-post.html)
2. [Wikipedia: Abstract factory pattern](http://en.wikipedia.org/wiki/Abstract_factory_pattern)
