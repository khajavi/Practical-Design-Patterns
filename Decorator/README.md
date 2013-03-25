# الگوی طراحی Decorator
انعطاف‌پذیری و تغییر رفتار نمونه‌ها، در زمان اجرا.

##keywords
1. wrapper
2. aggregation relationship
3. Open-Closed Principle (Classes should be open for extension, but closed for modification)

## Components
1. Component
تعریف اینترفیس و تعریف عملیات لازم.
2. ConcreteComponent
پیاده‌سازی اینترفیس و عملیات.
3. Decorator
این کلاس با کامپوننت، رابطهٔ اگریگیشن دارد و داخل خود، یک نمونه از کامپوننت را نگهداری می‌کند.
4. ConcreteDecoratorA

## مثال ۱
فرض کنید که یک بستنی فروش سه نوع بستنی لیوانی، قیفی و چوبی دارد. این بستنی فروش هنگام فروش هر یک از این بستنی‌ها طبق سلیقهٔ مشتری، بستنی را با عسل، کاکائو، شکلات، بادام و ... `تزئین` می‌کند. 


## بیشتر بخوانید
1. http://javapapers.com/design-patterns/decorator-pattern/ یک مثال خوب و ساده با جاوا
2. java.io.BufferedReader;
3. java.io.FileReader;
4. java.io.Reader;


