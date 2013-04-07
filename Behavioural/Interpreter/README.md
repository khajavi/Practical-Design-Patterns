<div dir="rtl">
# هدف
یک بازنمایی برای گرامر زبان داده شده تعریف می‌کند و مفسر توسط این باز نمایی، جملات زبان را تفسیر می کند.

# ساختار
![Interpreter UML](http://javaobsession.files.wordpress.com/2010/07/interpreter-pattern.png)

# نکات طراحی
وقتی از این الگو استفاده کنید که
- گرامر ساده‌ای وجود دارد که می‌تواند توسط درخت گرامر (Syntax tree) بازنمایی شود.
- کارایی زیاد مهم نیست.

# مثال‌های واقعی
<div dir="ltr">
- java.util.Pattern
- java.text.Normalizer
- All subclasses of java.text.Format
- All subclasses of javax.el.ELResolver
