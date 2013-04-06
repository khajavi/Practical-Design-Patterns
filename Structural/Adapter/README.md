<div dir="rtl">
# هدف
یک واسط را به واسط مورد نظر کلاینت تبدیل می‌کند و اجازه می‌دهد تا کلاس‌ها با اینترفیس‌های متفاوت و ناسازگار با یکدیگر کار کنند.

# ساختار
# نسخهٔ کلاس (وراثت چندگانه)
![Adpater (Class Version)](http://javaobsession.files.wordpress.com/2010/07/adapter-pattern-class1.png)

# نسخهٔ شیء (کامپوزیشن)
![Adapter (Object Version)](http://javaobsession.files.wordpress.com/2010/07/adapter-pattern-object.png)

# نکات طراحی
راه‌های پیاده‌سازی:

- چندوراثتی (Multiple Inheritance): کلاس Adapter،  رابط Adaptee و Target را پیاده‌سازی می‌کند. (در جاوا از implement می‌توان به چند وراثتی دست یافت)
- ترکیب شی (Object Composition)؛ کلاس Adapter، رابط Target را پیاده‌سازی می‌کند و درخواست‌های Target را برای Adaptee ترجمه می‌کند.

# اجزاء الگو
## Target
واسطی‌ست (اینترفیس) که کلاینت از آن استفاده می‌کند. 

## Client
شیئ‌ای‌ست که با اشیاء‌ای که با Target Interface مطابقت دارند، همکاری می‌کند.

## Adaptee
واسطی‌ست که با واسطِ درخواستی کلاینت ما ناسازگار است و قرار است توسط Adapter به واسط درخواستی کلاینت سازگار شود.

## Adapter
یک رابط را به رابط دیگر (متناسب با درخواست کلاینت) تبدیل می‌کند. درخواست کلاینت را می‌گیرد، و آن را برای Adaptee Interface ترجمه می‌کند.

این کلاس، رابط Target را پیاده‌سازی می‌کند

# مثال‌های واقعی
<div dir="ltr">
- java.util.Arrays#asList()
- java.io.InputStreamReader(InputStream) (returns a Reader)
- java.io.OutputStreamWriter(OutputStream) (returns a Writer)
- javax.xml.bind.annotation.adapters.XmlAdapter#marshal() and #unmarshal()


