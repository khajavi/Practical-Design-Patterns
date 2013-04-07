<div dir="rtl">
#هدف
به شیء این اجازه را می‌دهد که وقتی وضعیت درونی‌اش تغییر کرد، رفتارش را تغییر دهد. به نظر می‌رسد که شیء کلاس خود را عوض می‌کند.

# ساختار
![State Pattern UML](http://www.dofactory.com/Patterns/Diagrams/state.gif)

# اجزاء الگو
- Context
- State
- ConcreteState

# نکات طراحی
زمانی از این الگو استفاده کنید که
- رفتار شیء وابسته به وضعیت‌اش متغییر است و شیء بنا به وضعیت خود که در زمان اجرا مشخص می‌شود، تغییر حالتش متفاوت است.
- رفتارهای شیء توسط تعداد بسیار زیادی از متغییرهای شرطی تعیین می‌شود (اگر-آنگاه‌های زیاد).

# مثال
- برای طراحی Finite State Machine می‌توان از این الگو استفاه کرد.

# مثال‌های واقعی
<div dir="ltr">
- javax.faces.lifecycle.LifeCycle#execute() (controlled by FacesServlet, the behaviour is dependent on current phase (state) of JSF lifecycle)
