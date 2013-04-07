<div dir="rtl">
# هدف
وابستگی یک-به-چند بین اشیاء تعریف می‌کند بنابراین وقتی یک شیء وضعیت‌اش را تغییر می‌دهد، تمامی اشیاء وابسته به آن از آن تغییر مطلع شده و به صورت خودکار به روز می‌شوند.

# ساختار
![Observer UML](http://www.dofactory.com/Patterns/Diagrams/observer.gif)


# اجزاء الگو
- Subject
- Observer
- ConcreteSubject
- ConcreteObserver


# نکات طراحی
- Publishers + Subscribers = Observer Pattern
- Subjects + Observers = Observer Pattern
مفاهیم مرتبط
- Loos coupling
- one-to-many relationship
- minimized interdependency

این الگو زمانی اعمال می‌شود که Subject-ها و Observer-ها Loose Couple باشند.

# مثال‌های واقعی
<div dir="ltr">
- java.util.Observer/java.util.Observable (rarely used in real world though)
- All implementations of java.util.EventListener (practically all over Swing thus)
- javax.servlet.http.HttpSessionBindingListener
- javax.servlet.http.HttpSessionAttributeListener
- javax.faces.event.PhaseListener

