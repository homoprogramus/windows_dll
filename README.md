# windows_dll
A C++ dll creation and dynamic loading usage

## 1.Creation ##

Create the class Hello with a simple public function hello() printing 'Hello World'.

In .hpp add
```
#define HELLO __declspec(dllexport)
```

That will ease the use of `__declspec(dllexport)`.

Define the hello() function like this:

`static void HELLO hello();`

Implement the class in the .cpp file.

Build the dll

## 2.Dump the export ##

In a Visual Studio command prompt use link /dump /exports *your_dll* it will display the decorated name of your exported
function. It will display string like:

`?hello@Hello@@SAXXZ`

This is the decorated name of each functions. As you can see you have ?*function*@*Class*@*something*

Create a .def file which will give correspondence between the compiler decorated name and your name:


```
LIBRARY "your_library"
EXPORTS
    Hello_hello     = ?hello@Hello@@SAXXZ
```

Then recompile your dll with the def file in the Linker/Input/Module Definition File.

## 3.Use the dll ##

First load the lib `LoadLibrary("*your_library*")` in a `HINSTANCE` variable.

Find the function with `GetProcAddress(HINSTANCE, "function_name")` (tip: use auto as a return type)

Call the function with `(func)(parameters)`

Do not forget to `FreeLibrary(HINSTANCE)`