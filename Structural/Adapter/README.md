#الگوی طراحی Adapter
هدف: این الگو، اجازه می‌دهد تا دو اینترفیس ناسازگار با یکدیگر کار کنند.

راه‌های پیاده‌سازی:
1. چندوراثتی: کلاس Adapter، رو رابط Adaptee و Target را پیاده‌سازی می‌کند.
2. ترکیب شی (Object Composition)؛ کلاس Adapter، رابط Target را پیاده‌سازی می‌کند و درخواست‌های Target را برای Adaptee ترجمه می‌کند.

## Target
رابطی‌ست (اینترفیس) که کلاینت از آن استفاده می‌کند. 

## Client
شیئ‌ای‌ست که با اشیاء‌ای که با Target Interface مطابقت دارند، همکاری می‌کند.

## Adaptee


## Adapter
یک رابط را به رابط دیگر (متناسب با درخواست کلاینت) تبدیل می‌کند. درخواست کلاینت را می‌گیرد، و آن را برای Adaptee Interface ترجمه می‌کند.
این کلاس، رابط Target را پیاده‌سازی می‌کند

## بیشتر بخوانید
1. java.io.InputStreamReader(InputStream)
2. java.io.OutputStreamWriter(OutputStream)

