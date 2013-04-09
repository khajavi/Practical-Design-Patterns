<div dir="rtl">
# هدف
استفادهٔ دوبارهٔ بسیاری از اشیاء fine-grain را با اشتراک آن‌ها در سیستم، آسان می‌کند.

# ساختار
![Flyweight UML](http://javaobsession.files.wordpress.com/2010/07/flyweight-pattern1.png)


# اجزاء
- Flyweight
- ConcreteFlyweight
- UnsharedConcreteFlyweight (اختیاری، می‌توان در طراحی از این کلاس استفاده نکرد.)
- FlyweightFactory
- Client

# نکات طراحی
- شیء flyweight، شیئ است که استفاده از حافظه را با اشتراک‌گذاری اشیاء مشابه، کاهش می‌دهد. این روشی‌ست برای استفاده از تعداد بسیار زیادی از اشیاء مشابه که نمی‌توان همهٔ آن‌ها را در حافظه ایجاد کرد و یا  هزینهٔ زیادی در بر دارند.
- هر شیء flyweight دو نوع ویژگی دارد، ویژگی ذاتی و درونی، ویژگی عارضی.

وقتی از این الگو استفاده کنید که
- اشیاء بسیار زیادی دارید که داده‌های مشابهی دارند و هزینهٔ حافظهٔ آن‌ها زیاد است.
- اشیاء مشترک کم، می‌توانند جایگزین اشیاء به اشتراک گذاشته نشدهٔ زیاد شوند.
- هویت هر شیء چندان مهم نیست.

# مثال
وقتی بخواهیم ویرایشگری طراحی کنیم که نویسه‌ها را در ویرایشگر نمایش دهد، اگر بخواهیم برای هر نویسه یک شیء در نظر بگیریم، سربار زیادی برای سیستم خواهد داشت. راه حل ساده این است که برای هر یک از حروف الفبا یک شیء flyweight در نظر می‌گیریم. سپس به صورت اشتراکی از آن‌ها استفاده می‌کنیم.

# مثال‌های واقعی
<div dir="ltr">
- java.lang.Integer#valueOf(int) (also on Boolean, Byte, Character, Short and Long)

<div dir="rtl">
# اطلاعات بیشتر
<div dir="ltr">
1. [Flyweight Design Pattern; Java Papers](http://javapapers.com/design-patterns/flyweight-design-pattern/)
2. [C++ example of Flyweight Design Pattern](http://advancedcppwithexamples.blogspot.de/2010/10/c-example-of-flyweight-design-pattern.html)
3. [Source Making flyweight design pattern](http://sourcemaking.com/design_patterns/flyweight)
4. [Flyweight Design Pattern](http://dofactory.com/Patterns/PatternFlyweight.aspx)
5. [مثالی از بازی سودوکو پیاده‌شده توسط الگوی flyweight](http://cgeers.com/2008/03/08/flyweight-pattern/)
