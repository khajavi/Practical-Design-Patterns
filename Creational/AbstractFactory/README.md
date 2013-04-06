<div dir="rtl">
# هدف
بدون مشخص کردن کلاس‌های کانکرت، واسطی برای ساخت خانواده‌ای از اشیاء وابسته یا مرتبط با یکدیگر فراهم می‌کند.



# نکات طراحی
- وظیفهٔ این الگو، تعریفِ واسطی برای خانواده‌ای از محصولات است.
- اگر چند نوع محصول و چند کارخانهٔ مختلف برای تولید این محصولات داشته باشیم از این الگو استفاده می‌کنیم.
- وقتی که ساخت محصولات باید از سیستمی که از آن‌ها استفاده می‌کند مستقل باشد این الگو مفید است.

# ساختار
![Abstract Factory UML](http://javaobsession.files.wordpress.com/2010/07/abstract-factory1.png)

# مثال

کارخانه‌ها به سه دسته تقسیم می‌شوند (نوکیا/سامسونگ/اچ‌تی‌سی) و محصولات به دو دستهٔ (گوشی‌های هوشمند/گوشی‌های غیرهوشمند)
در این مثال ابتدا یک کلاس انتزاعی از کارخانه‌ها می‌سازیم که این کلاس دو متد دارد، یکی ساخت گوشی هوشمند آن کارخانه و دیگری ساخت گوشی غیرهوشمند آن کارخانه.

سپس از کلاس انتزاعی کارخانه، سه کلاس نوکیا و سامسونگ و اچ‌تی‌سی می‌سازیم که هر کدام از این کارخانه‌ها دو نوع گوشی هوشمند و غیر هوشمند خود را می‌سازند.

در این مثال، کلاینت ما از نام گوشی‌ها با خبر نیست. مثلاً نمی‌داند که گوشی هوشمند سامسونگ چیست. کلاینت درخواستش را اعلام می‌کند. مثلاً می‌گوید گوشی هوشمند سامسونگ را می‌خواهم. کلاس کانکرت کارخانهٔ سامسونگ درون کلاس ساخت گوشی هوشمند خود، گالاکسی‌اس۲ را می‌سازد.

متن کامل مثال: http://www.codeproject.com/Articles/331304/Understanding-and-Implementing-Abstract-Factory-Pa

# مثال‌های واقعی
<div dir="ltr">
- javax.xml.parsers.DocumentBuilderFactory#newInstance()
- javax.xml.transform.TransformerFactory#newInstance()
- javax.xml.xpath.XPathFactory#newInstance()

# بیشتر بخوانید
1. [Simple Factory vs. Factory Method vs. Abstract Factory](http://corey.quickshiftconsulting.com/1/post/2009/5/first-post.html)
2. [Wikipedia: Abstract factory pattern](http://en.wikipedia.org/wiki/Abstract_factory_pattern)
