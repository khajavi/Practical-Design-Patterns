<div dir="rtl">
# تعریف
Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

الگوی طراحی Facade، اینترفیس را ساده‌تر می‌کند.

# ساختار
![structure](http://www.dofactory.com/Patterns/Diagrams/facade.gif)

# participants
1. Facade
2. Subsystem classes


# Law of Demeter (LoD) or Principle of Least Knowledge
تنها با دوستان بی‌واسطهٔ خود مذاکره کنید. این اصل یکی از روش‌های ایجاد Loose Coupling است.

تنها متدهایی را صدا بزنید که متعلق به
1. شیء خودتان باشد.
2. آبجت‌هایی که توسط پارامتر به شء شما منتقل شده‌اند.
3. هر شیء‌ای که خودتان تولید یا نمونه‌سازی می‌کنید.
4. کامپوننت‌هایی خودتان (HAS-A)
هیچ کدام یک از راهنماهای بالا عنوان نمی‌کند که شما می‌توانید متدهای یک شیء که توسط متدهای دیگر برگردانده می‌شود را صدا بزنید، مثلاً کد زیر خلاف این اصل است:
```Java
public float getTemp() {
	return station.getThermometer().getTemperature();
}
```
یا مثلاً کد معروف جاوا:
```Java
System.out.println();
```

# اطلاعات بیشتر
1. http://zuta-developer.blogspot.com/2012/06/facade-pattern.html#.UVabkCEqgYQ
