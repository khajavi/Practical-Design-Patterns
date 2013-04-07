<div dir="rtl">
# هدف
واسط یکپارچه‌ای را برای مجموعه‌ای از واسط‌ها در زیر سیستم، ارائه می‌دهد. این الگو واسط سطح-بالاتری را تعریف می‌کند که استفاده از زیرسیستم را ساده‌تر می‌کند.

# ساختار
![Facade UML](http://javaobsession.files.wordpress.com/2010/07/facade-pattern.png)

# نکات طراحی
الگوی طراحی Facade، اینترفیس را ساده‌تر می‌کند.

زمانی از این الگو استفاده کنید که
- نیاز به واسط ساده‌ای دارید که دسترسی به سیستم پیچیده را فراهم کند.
- نیاز به کاهش کوپلینگ (اتصال‌ها) بین پیاده‌سازی‌های سیستم و کارخواه‌ها دارید.
- نیاز به لایه‌بندی زیرسیستم‌ها دارید.

# اجزاء الگو
- Facade
- Subsystem classes


# Law of Demeter (LoD) or Principle of Least Knowledge
تنها با دوستان بی‌واسطهٔ خود مذاکره کنید. این اصل یکی از روش‌های ایجاد Loose Coupling است.

تنها متدهایی را صدا بزنید که متعلق به
1. شیء خودتان باشد.
2. آبجت‌هایی که توسط پارامتر به شیء شما منتقل شده‌اند.
3. هر شیء‌ای که خودتان تولید یا نمونه‌سازی می‌کنید.
4. کامپوننت‌های خودتان (HAS-A)

هیچ کدام یک از راهنماهای بالا عنوان نمی‌کند که شما می‌توانید متدهای یک شیء که توسط متدهای دیگر برگردانده می‌شود را صدا بزنید، مثلاً کد زیر خلاف این اصل است:
<div dir="ltr">
```Java
public float getTemp() {
	return station.getThermometer().getTemperature();
}
```
<div dir="rtl">
یا مثلاً کد معروف جاوا:
<div dir="ltr">
```Java
System.out.println();
```
<div dir="rtl">
# مثال‌های واقعی
<div dir="ltr">
- javax.faces.context.FacesContext, it internally uses among others the abstract/interface types LifeCycle, ViewHandler, NavigationHandler and many more without that the enduser has to worry about it (which are however overrideable by injection).
- javax.faces.context.ExternalContext, which internally uses ServletContext, HttpSession, HttpServletRequest, HttpServletResponse, etc.
<div dir="rtl">
# اطلاعات بیشتر
<div dir="ltr">
1. http://zuta-developer.blogspot.com/2012/06/facade-pattern.html#.UVabkCEqgYQ
