<div dir="rtl">
# تعریف
استخوان‌بندی و شالودهٔ اصلی عملیات الگوریتم را تعریف می‌کند، و پیاده‌سازی هر مرحله را به زیرکلاس‌ها می‌سپارد. این الگو، به زیرکلاس‌ها این اختیار را می‌دهد که تا خودشان، مراحل الگوریتم را پیاده کنند بدون اینکه ساختار الگوریتم را تغییر دهند.


# ساختار
![UML Structure](http://yuml.me/77419b3e)


# نکات طراحی
در این الگو ساختار اصلی الگوریتم را در متدی به نام TemplateMethod طراحی می‌کنیم. این متد دارای یک سری عملیات اولیه (Primitive Operations) است. این متد را دسترسی پابلیک می‌دهیم و تمامی عملیات اولیه را ابسترکت و protected می‌کنیم تا کلاس‌های کانکرت به دلخواه خود توابع اولیهٔ مناسب خود را طراحی کنند.
- این الگو کنترل بیشتری نسبت به الگوی Strategy نسبت به الگوریتم‌های متفاوت دارد.
- الگوی استراتژی از Composition استفاده می‌کد و الگوی تمپلیت متد از وراثت. الگوی استراتژی flexibility بیشتری نسبت به تمپلیت متد دارد.
- الگوی تملیت متد با استفاده از متدهای Hook برای ساخت فریم‌ورک مناسب است.
- الگوی طراحی تملیت متد دارای Depenency است در صورتی که الگوی طراحی استراتژی به دلیل استفاده از کامپوزیشن عاری از Dependency است.
- الگوی طراحی تمپلیت متد از اصل هالیوود استفاده می‌کند، اصل هالیوود می‌گوید: با ما تماس نگیرید، ما با شما تماس می‌گیریم.
- [Hollywood principle - Wikipedia, the free encyclopedia](http://en.wikipedia.org/wiki/Hollywood_principle)
- این الگو مراحل را خود تعریف می‌کند اما در پیاده‌سازی هر یک از مراحل اختیار را به زیرکلاس‌ها می‌دهد.
- این الگو نمونه‌ای از Code Reuse است.
- هوک‌ها متدهایی هستند که کاری انجام نمی‌دهند یا عمل پیشفرضی در کلاس ابسترکت انجام می‌دهند. هوک‌ها «ممکن» است توسط زیرکلاس‌ها override شوند و عمل پیشفرض آن‌ها تغییر کند.
- برای جلوگیری override کردن متد تمپلیت توسط زیرکلاس‌ها، متند تمپلیت را final کنید.
- الگوی طراحی Factory Method نیز حالت خاصی از الگوی طراحی Template Method است.


# اجزاء الگو
## AbstractClass 
1. عملیات اولیه را به صورت ابسترکت «معرفی» می‌کند. البته اگر عملیاتی اختیاری‌ست یعنی کلاس‌های کانکرت می‌توانند آن را override کنند یا نه، می‌توان چنین عملیات اختیاری را به صورت Hook تعریف کرد.
2. متد TemplateMethod را که ساختار الگوریتم است را «پیاده‌سازی» می‌کند. این متد در کلاس‌های کانکرت Override نمی‌شود. (final در جاوا)
 
## ConcreteClass
هر کانکرت کلاسی، عملیات اولیه را مطابق کلاس خود پیاده سازی می‌کند.

# Hook
1. متدهای start و stop و init و destroy در کلاس Applet در جاوا.
2. متد paint در کلاس JFrame در کتابخانهٔ جاوا.

# مثال (تولید کنندهٔ سند)
![DocumentGenerator](http://yuml.me/40441c19)
روال تولید سند برای انواع و اقسام سندها یکسان است:

1. فسمت Header سند را تولید کن.
2. قسمت بدنهٔ سند را تولید کن.
3. جزئیات سند را تولید کن.

اما پیاده‌سازی هر یک از این روال‌ها برای ساخت PDF و HTML و Doc و ... متفاوت است. بنابراین می توانیم از الگوی طراحی TemplateMethod استفاده کنیم.

# مقایسهٔ سه الگوی طراحی
1. Template Method: زیرکلاس‌ها تصمیم می گیرند که مراحل اجرای الگوریتم را چطور پیاده سازی کنند.
2. Strategy: رفتارهای قابل تغییر را کپسوله می‌کند و از واگذاری و دلگیشن استفاده می‌کند تا در زمان اجرا تصمیم بگیرد که کدام رفتار اعمال شود.
3. Factory Method: زیرکلاس‌ها تصمیم می‌گیرند که کدام یک از کلاس‌های کانکرت، ایجاد شوند.

# مثال‌های واقعی
<div dir="ltr">
- All non-abstract methods of java.io.InputStream, java.io.OutputStream, java.io.Reader and java.io.Writer.
- All non-abstract methods of java.util.AbstractList, java.util.AbstractSet and java.util.AbstractMap.
- javax.servlet.http.HttpServlet, all the doXXX() methods by default sends a HTTP 405 "Method Not Allowed" error to the response. You're free to implement none or any of them.

# بیشتر
1. [الگوریم مرتب‌سازی به وسیلهٔ الگوی طراحی Template Method](http://sourcemaking.com/design_patterns/template_method/cpp/2) 
2. [Template method design pattern in java](http://javapostsforlearning.blogspot.com/2013/03/template-method-design-pattern-in-java.html)
