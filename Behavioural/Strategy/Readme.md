<div dir="rtl">
# هدف
خانواده‌ای از الگوریتم ها را تعریف می‌کند، هر یک را کپسوله می‌کند و آن‌ها را جابه‌جا پذیر می‌کند. الگوی استراتژی اجازه می‌دهد که الگوریتم‌ها مستقل از کارخواهی که از آن‌ها استفاده می‌کند، تغییر کنند.

# نام دیگر
Policy Pattern

# ساختار
![Strategy Pattern](http://yuml.me/diagram/scruffy;/class/// Non-specific Strategy Class Diagram, [Caller]<>->[<<Interface>>;Algorithm], [<<Interface>>;Algorithm]^-.-[ConcreteAlgorithm1], [<<Interface>>;Algorithm]^-.-[ConcreteAlgorithm2])

# Keywords
- Behavioral Pattern
- Strategy at runtime (Change Behavior at Runtime)
- Composition (HAS-A is better than IS-A)

# نکات طراحی
- در الگوی طراحی استراتژی سعی می‌کنیم که رفتارهای غیرثابت و متفاوت `(استراتژی‌های متفاوت)` را از کلاس خارج کنیم و به طور مستقل آن‌ها را کپسوله کنیم. در این صورت هر کلاس، هر کدام از الگوریتم‌هایی که نیاز داشته باشند را درون خود استفاده می‌کنند. همچنین این الگو اجازه می‌دهد تا هر یک از کلاس‌ها هر وقت که بخواهند، `استراتژی` خودشان را تغییر دهند.

- به انتخاب و تغییر رفتار (استراتژی) مناسب در زمان اجرا strategy at runtime می‌گوییم.
- رفتارها و `استراتژی‌هایی` که طول ساختار وراثتی کلاس تغییر می‌کند را مشخص کنید و آن رفتارها را از کلاس خارج کنید. و آن‌ها را جداگانه کپسوله کنید.
- آنچه که تغییر می‌کند را از آنچه ثابت می‌ماند جدا کنید.
- مزیت `استراتژی` این است که اگر بخواهیم در طول توسعهٔ نرم‌افزار رفتارها و `استراتژی‌های` جدیدی تعریف کنیم، نیازی به تغییر کلاس‌های اصلی که از این رفتارهای استفاده می‌کنند نداریم.


# اجزاء
1. Strategy
2. ConcreateStrategy
3. Context



# Client Code
```
Context context = new Context(new ConcreateStrategy1());
context.AlgorithmInterface();
```

#مثال ۱
فرض کنید که کلاسی داریم به نام `Car()` با متودی به نام `run()` آنگاه می‌توانیم آن را به صورت زیر پیاده کنیم:
```
Car car = new Car();
car.run();
```
حالا اگر بخواهیم هنگامی که ماشین روشن است، رفتار ماشین را تغییر دهیم چه کار کنیم؟ مثلاً بخواهیم در نرم‌افزار بازی دکمهٔ `Boost‍` را شبیه‌سازی کنیم. چندین روش وجود دارد یکی این که از متغییرهای شرطی و ... استفاده کنیم راه دیگر استفاده از `الگوی طراحی استراتژی` هست. مثلاً‌ می‌تواین حین بازی موتور میاشین را عوض کنیم!! مثال:
```
Class Car()
{
    this.motor = new Motor(this) 

    // passing "this" is important for the motor so it knows what it is running

    method run()
    {
        this.motor.run()
    }

    method changeMotor(motor)
    {
        this.motor=motor 
    }

}
```

## مثال ۲
فرض کنید که یک کارخانهٔ تلفن گوشی همراه داریم. که انواع و اقسام گوشی‌ها را تولید می‌کند. خب برای پیاده‌سازی کلاس‌های این گوشی‌ها چه کنیم؟ 

اولی: آیا می‌توانیم تمامی رفتارهای مختلف و قابلیت‌های گوشی‌های مختلف رو در کلاس مادر تعریف کنیم؟ 

دومی: خیر، چون همهٔ‌ گوشی‌ها همهٔ قابلیت‌ها را پیاده نمی‌کنند. بعضی از گوشی‌ها دوربین دارند بعضی ندارند. بعضی رادیو دارند بعضی ندارند. بعضی قابلیت اتصال به کامپیوتر دارند و بعضی ندارند.

اولی: خب حالا چه کار کنیم؟

دومی: خب همهٔ قابلیت‌ها را در کلاس مادر تعریف نمی‌کنیم. سعی می‌کنیم قابلیت‌ها را در طول ساختار وراثت به سیستم اعمال کنیم.

اولی: اولاً‌ این روش معقولانه‌ای نیست چون برای اضافه کردن هر رفتار و قابلیت جدید باید کلاس و ساختار وراثت را دچار تغییر کنیم. دوم این که باعث ایجاد `کدهای تکراری` می‌شود.

دومی: راهکار چیست؟

اولی: استفاده از `الگوی استراتژی` یعنی رفتارهای متغیر را از رفتارهای ثابت جدا کنیم و رفتارهای متغیر را ساختار وراثتی کلاس خارج کنیم. و آن‌ها را کپسوله کنیم.

# مثال ۳
فرض کنید که قرار است کلاسی بسازیم که آرایهٔ ورودی را مرتب کند. می‌خواهیم بر اساس نوع داده‌ها، ترتیب داده‌ها و پراکندگی داده‌ها الگوریتم مرتب‌سازی مناسب را در run-time اعمال کنیم. برای انجام چنین کاری می‌توانیم از الگوی استراتژی استفاده کنیم.

# مثال‌های واقعی

<div dir="ltr">
- java.util.Comparator#compare(), executed by among others Collections#sort().
- javax.servlet.http.HttpServlet, the service() and all doXXX() methods take HttpServletRequest and HttpServletResponse and the implementor has to process them (and not to get hold of them as instance variables!).
- javax.servlet.Filter#doFilter()
<div dir="rtl">
# اطلاعات بیشتر

<div dir="ltr">
1. [How does the Strategy Pattern work?](http://stackoverflow.com/questions/91932/how-does-the-strategy-pattern-work)
2. ص ۳۴۹ کتاب Gang of for
3. ص ۱۲ کتاب Head First Design Pattern
4. [Encapsulate a family of algorithms using Strategy Pattern](http://taskinoor.wordpress.com/2011/04/03/encapsulate_algorithm_strategy/) یک مثال خیلی خوب


