# هدف
واسطی برای ساخت اشیاء ایجاد می‌کند، اما به زیرکلاس‌ها اجازه می‌دهد که تصمیم بگیرند که چه کلاسی را نمونه‌سازی کنند. این الگو اجازه می‌دهد تا نمونه‌برداری کلاس، به زیرکلاس‌ها معوق شود.

# نام دیگر
Virtual Constructor

# نکات طراحی
- وابستگی به زیرکلاس را برای ساخت اشیاء از بین می‌برد.
- برای زیرکلاس‌ها hook ارائه می‌کند.

- Connects parallel class hierarchies.
- در الگوی طراحی Factory Method از Simple Factory استفاده می‌کنیم.
- در Simple Factory تنها یک کارخانه داریم. اما اگر چند کارخانه داشته باشیم که همگی این کارخانه‌ها محصولات مشابهی تولید کنند مثلاً همگی موبایل تولید می‌کنند (اما هر کارخانه پیاده‌سازی خودش را دارد) در چنین حالتی از Factory Method استفاده می‌کنیم. به این صورت یک رابط برای کارخانه‌ها ایجاد می‌کنیم و پیاده‌سازی متود ساخت محصول را به کارخانه‌ها واگذار می‌کنیم. هر یک از کارخانه‌ها از Simple Factory برای تولید محصولاتش استفاده می‌کند.
- به روش بالا می گوییم: Allowing the subclasses to decide یا Real-time decision
- برای اینکه پارامترهای Concrete Factory بتوانند `Type-Safe` باشند، می‌توانیم از `enum` استفاده کنیم و یا روش‌های بهتر.
- وقتی که نمونه‌سازی اشیاء را در یک آبجکت یا متد، کپسوله کنیم، باعث بالا رفتن maintenance می‌شود و باعث می‌شود از کدهای اضافی و مجدد خودداری شود.
- در این الگو اصل Dependency Inversion Principle رعایت می‌شود.

# ساختار
![Factory Method Pattern UML](http://javaobsession.files.wordpress.com/2010/07/factory-method.png)


![Factory Method Pattern](http://yuml.me/f1b5a95b)



# مثال
ساخت موبایل از دو کارخانهٔ متفاوت

## Product (Mobile)
یک واسط برای تمامی موبایل‌ها تعریف می‌کنیم و ویژگی‌ها و رفتارهای مشترک را ذکر می‌کنیم.

1. نام موبایل
2. رنگ

## ConcreateProduct
واسط موبایل را برای موبایل‌های مختلف پیاده‌سازی می‌کنیم.

1. Nokia N900
2. Nokia N95
3. Motorola Atrix
4. Motorola A1200

## Creator/Factory
واسط کارخانه
createMobile()

## ConcreteCreator/ConcreteFactry
هر کدام از کارخانه‌ها باید واسط کارخانه را پیاده‌سازی کنند.

1. NokiaFactory
2. MotorolaFactory
3. ...

## Client
```
Factory  factory =  new NokiaFactory()
Car car = factory.createMobile(مشخصات موبایل، نام موبایل، مثل رنگ و ...)
```
![Mobile Factory](http://yuml.me/679b958b)

## بیشتر بخوانید
1. کلاس SAXParserFactory
2. http://javapapers.com/design-patterns/factory-method-pattern/
3. http://stackoverflow.com/questions/9963090/factory-pattern-vs-factorymethod-pattern
4. http://c2.com/cgi/wiki?FactoryMethodPattern



