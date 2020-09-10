#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct lesson
{
	int beg;
	int end;
	int lenght;
};

int main()
{
	srand(time(0));
	lesson* list;
	list = new lesson[300];

	for (int i = 0; i < 300; i++)
	{
		list[i].beg = rand() % 232 + 480;
		list[i].lenght = rand() % 8 + 2;
		list[i].end = list[i].beg + list[i].lenght;
	}

	cout << "==============================================================" << endl;
	cout << "list of lessons" << endl;
	cout << "==============================================================" << endl;

	int coutBeg1, coutBeg2, coutEnd1, coutEnd2;
	for (int i = 0; i < 300; i++)
	{
		coutBeg1 = list[i].beg % 60; coutBeg2 = (list[i].beg - coutBeg1) / 60;
		coutEnd1 = list[i].end % 60; coutEnd2 = (list[i].end - coutEnd1) / 60;
		cout << i + 1 << "\tbegin in " << coutBeg2 << ":";
		if (coutBeg1 < 10) cout << "0" << coutBeg1;
		else cout << coutBeg1;
		cout << "\tend in " << coutEnd2 << ":";
		if (coutEnd1 < 10) cout << "0" << coutEnd1;
		else cout << coutEnd1;
		cout << "\tlenght " << list[i].lenght << endl;
	}

	int sort = 1;
	lesson temp;
	while (sort != 0)
	{
		sort = 0;
		for (int i = 0; i < 299; i++)
		{
			if (list[i].end > list[i + 1].end)
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				sort = 1;
			}
		}
	}

	cout << "==============================================================" << endl;
	cout << "the order of attending lessons for professor" << endl;
	cout << "==============================================================" << endl;

	int cnt = 1, last = 0, count = 1;
	for (int i = 1; i < 300; i++)
	{
		if (list[i].beg >= list[last].end)
		{
			coutBeg1 = list[last].beg % 60; coutBeg2 = (list[last].beg - coutBeg1) / 60;
			coutEnd1 = list[last].end % 60; coutEnd2 = (list[last].end - coutEnd1) / 60;
			cout << count << "\tbegin in " << coutBeg2 << ":";
			if (coutBeg1 < 10) cout << "0" << coutBeg1;
			else cout << coutBeg1;
			cout << "\tend in " << coutEnd2 << ":";
			if (coutEnd1 < 10) cout << "0" << coutEnd1;
			else cout << coutEnd1;
			cout << "\tlenght " << list[last].lenght << endl;
			cnt++;
			last = i;
			count++;
		}
	}
	coutBeg1 = list[last].beg % 60; coutBeg2 = (list[last].beg - coutBeg1) / 60;
	coutEnd1 = list[last].end % 60; coutEnd2 = (list[last].end - coutEnd1) / 60;
	cout << count << "\tbegin in " << coutBeg2 << ":";
	if (coutBeg1 < 10) cout << "0" << coutBeg1;
	else cout << coutBeg1;
	cout << "\tend in " << coutEnd2 << ":";
	if (coutEnd1 < 10) cout << "0" << coutEnd1;
	else cout << coutEnd1;
	cout << "\tlenght " << list[last].lenght << endl;

	cout << "==============================================================" << endl;
	cout << "max of lessons that professor can attend: " << cnt << endl;
	cout << "==============================================================" << endl;
}