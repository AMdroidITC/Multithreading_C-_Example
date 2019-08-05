#include "pch.h"
#include<thread>
#include<chrono>
#include<queue>
#include<ctime>
#include <iostream>
#include<vector>
using namespace std;
 /*void print(queue<int> &other)
{
	for (int i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << other.front() << " ";
		other.pop();

	}	
} */

void buffer(queue<int> &other, vector<int> &vec)
{
	//this_thread::sleep_for(chrono::milliseconds(5000));
		for (int i = 0; i < 1000; i++)
		{
			if (!other.empty())
			{
				int tmp1 = rand() % 10;
				bool tmp2 = true;
				if (tmp1 <= 5)
				{
					tmp2 = true;
				}
				else
					tmp2 = false;
				if (tmp2)
				{
					
					vec.push_back(other.front());
					other.pop();
				}
				else
				{
					i--;
				}
			}
			else
			{
				i--;
			}
		}
}

int main()
{
	srand(time(NULL));
	queue<int> qt;
	vector<int> vec;
	bool tr = true;
	thread th(buffer, ref(qt), ref(vec));
	

	for (int i = 0; i < 1000; i++)
	{		
		//this_thread::sleep_for(chrono::milliseconds(1));
		int a = rand() % 20;
		qt.push(a);
		//cout << qt.front() << " ";
		cout << a << " ";
	}


	th.join();
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << vec[i] << " ";
	}
	
	
}


