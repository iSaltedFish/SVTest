#include <vector>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define LOOPNUM 1000000


#define TEST
#define MASTER
#define MASTER1

void display(vector<string>& queue, int size)
{
	for (int i=0; i<size; i++)
	{
		printf("%s  ", queue[i].c_str());
	}
	printf("\n");
}

int StrToInt(const std::string& str)
{
//	int i = 0;
//	std::stringstream ss;
//	ss << str;
//	ss >> i;
//	return i;

	int i = atoi(str.c_str());
	return i;
}

void shuffle(vector<string>& queue, int size)
{
	for (int i=size-1; i>0; --i)
	{
		srand((unsigned)time(NULL));
		swap(queue[i], queue[rand() % (i + 1)]);
	}
}

void swap(string& s1, string& s2)
{
	string tmp = s1;
	s1 = s2;
	s2 = tmp;
}


void image(vector<string>& pub)
{
		int loop = 0;
		int cnt = 0;
	
		while (loop < LOOPNUM)
		{
			random_shuffle(pub.begin(), pub.end());
			
			// display(pub, 40);
	
			sort(pub.begin(), pub.begin() +3);
	
			vector<int> arr(6, 0);
	
			// testdata
			//{ pub[0] = "3h"; pub[1] = "3h"; pub[2] = "7"; pub[3] = "322"; pub[4] = "8oqs"; pub[5] = "5sbn"; }
	
			for (int i=0; i<6; i++)
			{
				arr[i] = StrToInt(pub[i].substr(0, 1));
			}
	/*
			for (int i=0; i<6; i++)
			{
				printf("%d	", arr[i]);
			}
			printf("\n");
	*/
			if (arr[0] == 4 || arr[0] == 7)
			{
				if (arr[1] == 7)
				{
					if (arr[2] == 7)
					{
						// do nothing
					}
					else
					{
						swap(pub[2], pub[5]);
					}
				}
				else
				{
					if (arr[2] == 7)
					{
						swap(pub[1], pub[4]);
					}
					else
					{
						swap(pub[1], pub[4]);
						swap(pub[2], pub[5]);
					}
				}
			}
			else
			{
				if (arr[1] == 4 || arr[1] == 7)
				{
					if (arr[2] == 7)
					{
						if (arr[0] <= 2)
						{
							// do nothing
						}
						else
						{
							swap(pub[0], pub[3]);
						}
					}
					else
					{
						if (arr[0] <= 2)
						{
							swap(pub[2], pub[5]);
						}
						else
						{
							swap(pub[0], pub[3]);
							swap(pub[2], pub[5]);
						}
					}
				}
				else
				{
					if (arr[2] == 4 || arr[2] == 7)
					{
						if (arr[1] <= 2)
						{
							// do nothing
						}
						else
						{
							if (arr[0] <= 2)
							{
								swap(pub[1], pub[4]);
							}
							else
							{
								swap(pub[0], pub[3]);
								swap(pub[1], pub[4]);
							}
						}
					}
					else
					{
						swap(pub[0], pub[3]);
						swap(pub[1], pub[4]);
						swap(pub[2], pub[5]);
					}
				}
			}
	/*
			for (int i=0; i<6; i++)
			{
				printf("%s	", pub[i].c_str());
			}
			printf("\n");
	
	*/
			random_shuffle(pub.begin()+4, pub.end());
	
			int inhand = 5;
			bool flag1 = false;
			bool flag2 = false;
			
			for (int i=0; i<inhand; i++)
			{
				// if (pub[i].substr(0, 2) == "5s")
					// inhand++;
				
				if ((pub[i].substr(0, 1) == "2" || pub[i].substr(0, 1) == "1") && pub[i].substr(0, 4) != "2han")
				{
					flag1= true;
					break;
				}
			}

			if (flag1)
				cnt++;
	
			loop++;
		}
	
	printf("cnt=%d\n", cnt);

	return;
}

int main()
{
	srand((unsigned)time(NULL));

	// your deck
	string a[40] = {
			"1gbl", "1gbl", "1gbl",
			"2doub", "2doub", "2doub", "2han", "2han", "2han", "2lk", "2lk", "2lk", "2hyg", "2hyg", "2hyg", 
			"332", "332", "332", "3h","3h", "322", "322", 
			"4l", "4l", "4l", 
			"5sbn", "5sbn", "5w", "5w",
			"6", "6",
			"7", "7", "7",
			"8oqs", "8oqs", "8oqs",
			"9ny", "9ny", "9ny" 
		};
	
	vector<string> pub(&a[0], &a[40]);

	image(pub);

	return 0;
}

