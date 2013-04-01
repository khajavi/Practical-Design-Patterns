# تعریف
Provides a way to access the elements of an aggregate object without exposing its underlying represenation.

# ساختار
![UML](http://www.dofactory.com/Patterns/Diagrams/iterator.gif)

# Participants
1. Iterator
2. ConcreteIterator
3. Aggregate
4. ConcreteAggregatge

# موارد استفاده
وقتی کالکشن‌ها و کانتینرهای متفاوتی داشته باشیم: list، vector، array، arrayList، set, multiset, queue, map, multimap و ... می‌توانیم با استفاده از Iterator یک اینترفیس یکسان برای دسترسی به محتوای این کانتینرها بنویسم. در این الگوی طراحی برای دسترسی به داده‌های کانتینرها لازم نیست از ساختمان داده‌های تک تک کانتینرها سردر بیاوریم. 

# بیشتر
1. java.util.Iterator, java.util.ArrayList
2. [Java Iterator](http://javapapers.com/core-java/java-iterator/)
3. [Understanding and Implementing the Iterator Pattern in C# and C++](http://www.codeproject.com/Articles/362986/Understanding-and-Implementing-the-Iterator-Patter)
