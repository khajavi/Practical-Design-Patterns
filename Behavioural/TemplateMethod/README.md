<div dir="rtl">
# تعریف
<div dir="ltr">
Define the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.
<div dir="rtl">

در این الگو ساختار اصلی الگوریتم را در متدی به نام TemplateMethod طراحی می‌کنیم. این متد دارای یک سری عملیات اولیه (Primitive Operations) است. این متد را دسترسی پابلیک می‌دهیم و تمامی عملیات اولیه را ابسترکت و protected می‌کنیم تا کلاس‌های کانکرت به دلخواه خود توابع اولیهٔ مناسب خود را طراحی کنند.

# Participants
## AbstractClass 
1. عملیات اولیه را به صورت ابسترکت «معرفی» می‌کند.
2. متد TemplateMethod را که ساختار الگوریتم است را «پیاده‌سازی» می‌کند. 
## ConcreteClass
هر کانکرت کلاسی، عملیات اولیه را مطابق کلاس خود پیاده سازی می‌کند.

# مثال (تولید کنندهٔ سند)
روال تولید سند برای انواع و اقسام سندها یکسان است.
1. فسمت Header سند را تولید کن.
2. قسمت بدنهٔ سند را تولید کن.
3. جزئیات سند را تولید کن.
اما پیاده‌سازی هر یک از این روال‌ها برای ساخت PDF و HTML و Doc و ... متفاوت است. بنابراین می توانیم از الگوی طراحی TemplateMethod استفاده کنیم.
