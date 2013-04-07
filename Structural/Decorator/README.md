<div dir="rtl">
# هدف
وظایف و قابلیت‌های بیشتری را به صورت داینامیک به شیء اضافه می‌کند. دکوریتورها برای توسعهٔ رفتارها و قابلیت‌ها روش انعطاف‌پذیر جایزینی را برای زیرکلاس‌سازی ارائه می‌دهند.

# نام دیگر
Wrapper

# ساختار
![Decorator UML](http://javaobsession.files.wordpress.com/2010/07/decorator-pattern.png)

# نکات طراحی
- انعطاف‌پذیری و تغییر رفتار نمونه‌ها، در زمان اجرا.
- اصل Open-Closed: کلاس‌ها باید برای توسعه و گسترش باز باشند اما برای تغییر بسته.
- کلاس Decorator از aggregation استفاده می‌کند.
زمانی از این الگو استفاده کنید که
- بدون زیرکلاس‌سازی یا تغییر کد کلاس اولیه، نیاز به تغییر رفتار آن کلاس دارید.
- اصلاح رفتار یک شیء باید داینامیک باشد.
- نیاز به ارائهٔ قابلیتی هستید که بتواند ویژگی‌های مختلف مستقلی را به کلاس اضافه کند به طوری که هر ترکیب یا ترتیبی از این ویژگی‌ها قابل اعمال باشد.


# اجزاء الگو
- Component: تعریف اینترفیس و تعریف عملیات لازم.
- ConcreteComponent: پیاده‌سازی اینترفیس و عملیات.
- Decorator: این کلاس با کامپوننت، رابطهٔ اگریگیشن دارد و داخل خود، یک نمونه از کامپوننت را نگهداری می‌کند.
- ConcreteDecoratorA

# مثال ۱
فرض کنید که یک بستنی فروش سه نوع بستنی لیوانی، قیفی و چوبی دارد. این بستنی فروش هنگام فروش هر یک از این بستنی‌ها طبق سلیقهٔ مشتری، بستنی را با عسل، کاکائو، شکلات، بادام و ... `تزئین` می‌کند. 

# مثال‌های واقعی
<div dir="ltr">
- All subclasses of java.io.InputStream, OutputStream, Reader and Writer have a constructor taking an instance of same type.
- java.util.Collections, the checkedXXX(), synchronizedXXX() and unmodifiableXXX() methods.
- javax.servlet.http.HttpServletRequestWrapper and HttpServletResponseWrapper
<div dir="rtl">

# بیشتر بخوانید
<div dir="ltr">
1. http://javapapers.com/design-patterns/decorator-pattern/ یک مثال خوب و ساده با جاوا

