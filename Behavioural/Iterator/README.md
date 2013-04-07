<div dir="rtl">
# تعریف
روشی برای دستری به عناصر یک شیء اگریگیت فراهم می‌کند بدون اینکه اصول پیاده‌سازی و ساختمان دادهٔ لایهٔ زیرین اگریگیت را نمایش دهد.

# ساختار
![Iterator UML](http://javaobsession.files.wordpress.com/2010/07/iterator-pattern.png)


# اجزاء الگو
- Iterator
- ConcreteIterator
- Aggregate
- ConcreteAggregatge

# نکات طراحی
زمانی از این الگو استفاده کنید که
- نیاز دارید تا روش یکپارچه‌ای را برای پیمایش عناصر یک مجموعه (کالکشن) فراهم کنید بدون این که ساختمان داده‌های کالکشن را افشا کنید.
- نیاز به واسط مشترکی برای پیمایش ساختمان داده‌های تجمعی مختلف دارید.
- وقتی کالکشن‌ها و کانتینرهای متفاوتی داشته باشیم: list، vector، array، arrayList، set, multiset, queue, map, multimap و ... می‌توانیم با استفاده از Iterator یک اینترفیس یکسان برای دسترسی به محتوای این کانتینرها بنویسم. در این الگوی طراحی برای دسترسی به داده‌های کانتینرها لازم نیست از ساختمان داده‌های تک تک کانتینرها سردر بیاوریم. 

# مثال‌های واقعی
<div dir="ltr">
- All implementations of java.util.Iterator (thus among others also java.util.Scanner!).
- All implementations of java.util.Enumeration
<div dir="rtl">

# اطلاعات بیشتر
<div dir="ltr">
1. java.util.Iterator, java.util.ArrayList
2. [Java Iterator](http://javapapers.com/core-java/java-iterator/)
3. [Understanding and Implementing the Iterator Pattern in C# and C++](http://www.codeproject.com/Articles/362986/Understanding-and-Implementing-the-Iterator-Patter)
