<div dir="rtl">
# هدف
شیء‌ای را تعریف می‌کند که نحوهٔ ارتباط بین مجوعه‌ای از اشیاء را کپسوله می‌کند. این الگو با جلوگیری ارتباط صریح بین اشیاء از جفتگری ضعیف (loose coupling) پشتیبانی می‌کند.

# ساختار
![UML](http://i.imgur.com/0wPMI3h.png)

# نکات طراحی
- مانند hub عمل می‌کند.

# اجزاء طراحی
- Mediator
- ConcreteMediator
- Colleague
- ConcreteColleague
# مثال
- اتاق چت
- برج مراقبت هواپیماها
- روترها

# مثال‌های واقعی
<div dir="ltr">
- java.util.Timer (all scheduleXXX() methods)
- java.util.concurrent.Executor#execute()
- java.util.concurrent.ExecutorService (the invokeXXX() and submit() methods)
- java.util.concurrent.ScheduledExecutorService (all scheduleXXX() methods)
- java.lang.reflect.Method#invoke()
