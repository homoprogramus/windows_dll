#include <iostream>
#include <Windows.h>

int main()
{
	HINSTANCE hello = LoadLibrary("hello_dll.dll");
	if(!hello)
	{
		std::cout << "Cannot load dll" << std::endl;
		return EXIT_FAILURE;
	}
	auto func = GetProcAddress(hello, "Hello_hello");
	if(!func)
	{
		std::cout << "Cannot locate the function" << std::endl;
		return EXIT_FAILURE;
	}

	(func) ();

	FreeLibrary(hello);

	return EXIT_SUCCESS;
}