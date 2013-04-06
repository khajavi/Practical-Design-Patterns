<div dir="rtl">
# هدف
1. تضمین می‌کند که کلاس تنها یک نمونه داشته باشد و دسترسی سراسری (globale) برای آن فراهم می‌کند.

# الگوی طراحی Singleton
هدف: هر گاه بخواهیم مطمئن شویم که فقط یک نمونه از کلاس می‌تواند وجود داشته باشد، و دسترسی سراسری به آن داشته باشیم، از این الگو استفاده می‌کنیم

1. کانستراکتور کلاس را پرایویت می‌کنیم تا کسی نتواند آن کلاس را خارج از کلاس new کند.
2. داخل کلاس یک متود استاتیک تعریف می‌کنیم و تنها یک نمونه از کلاس تولید می‌کنیم. اگر قبلاً یک نمونه تولید شده بود، همان نمونهٔ قبلی را برمی‌گردانیم.

# ساختار
![UML](http://javaobsession.files.wordpress.com/2010/06/56b5c960.png)

# Multithreading and Singleton
1. [Singleton in multi-threaded environment](http://taskinoor.wordpress.com/2011/04/18/singleton_multithreaded/)
2. [lazy initialization](http://en.wikipedia.org/wiki/Lazy_initialization)
3. باید این الگو را طوری به کار ببریم که thread safe باشد.

# Double-checked locking
در محیط‌های چند نخی، گرفتن و آزاد کردن lock خیلی هزینه‌بر است و ممکن است تعداد این درخواست‌ها خیلی خیلی زیاد شود. برای کاهش سربار lock می‌توان پس از اینکه فلگ را چک کردیم lock کنیم تا سربار کاهش یابد.
1. [Double-checked locking](http://en.wikipedia.org/wiki/Double-checked_locking)
2. [Double-checked locking and the Singleton pattern](http://www.ibm.com/developerworks/java/library/j-dcl/index.html)
3. [The "Double-Checked Locking is Broken" Declaration](http://www.cs.umd.edu/~pugh/java/memoryModel/DoubleCheckedLocking.html)

# جنبه‌های منفی
1. تا زمانی که سازندهٔ کلاس سینگلتون خصوصی‌ست، اشتقاق و زیرکلاس‌سازی امکان ناپذیر است.

# بیشتر بخوانید
1. http://stackoverflow.com/questions/86582/singleton-how-should-it-be-used
2. http://www.yolinux.com/TUTORIALS/C++Singleton.html
3. http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
