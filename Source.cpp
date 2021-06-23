#include "Header.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	//SetPos(45, 8);
	/*for (int j = 0; j < 3; j++) 
	{
		cout << "\rLoading   \rLoading";
		for (int i = 0; i < 3; i++) 
		{
			cout << ".";
			Sleep(1000);
		}
	}*/
	system("cls");

	PlaySound(TEXT("sred.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	Menu();
	return 0;
}