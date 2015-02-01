#include <iostream>
#include <conio.h>
int main(void)
{
	unsigned char znak;
	znak = getch();
	//std::cout << "Przycisk" << static_cast<float>(znak);

	while(kbhit())
	{
		znak = getch();
		std::cout << "Przycisk: " << static_cast<int>(znak);
	}
	getchar();
	return 0;
}