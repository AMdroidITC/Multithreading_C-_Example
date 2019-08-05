#include "pch.h"
#include<ctime>
#include<time.h>
#include<queue>
#include <iostream>
using namespace std;

long chap(int orer)
{
	int rope = orer * 24 * 60;
	int qanak = rope / 15;
	return qanak * 262144;
}

class Buffer
{
private:
	float *buff;
	long size;
	int it;
	int curr = 0;
public:
	Buffer(int n=3)
	{
		//size = chap(n);
 		size = 100000;
		buff = new float[size];
		it = -1;
	}
	void push(float a)
	{
		cout << "buffer" << endl;
		if (curr <= size)
		{
			it++;
			buff[it] = a;
			//cout << buff[it] << endl;
			++curr;
		}
		else
		{
			cout << "there is no space in buffer" << endl;
		}
	}
	int  top()
	{
		return buff[curr - 1];
	}
	void pop()
	{
		buff[curr] = NULL;
		curr--;
	}
	bool isfull()
	{
		if (curr == size)
		{
			return true;
		}
		else
			return false;
	}
	bool empty()
	{
		if (curr == 0)
		{
			return true;
		}
		else
			return false;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << buff[i] << " ";
		}
	}

};

class Kont
{
private:
	queue<float> arr;
	int size;
	int curr =0;
	Buffer buff;
 	int it=0;
public:	
	Kont()
	{
		size = 10;
		for (int i = 0; i <= size; i++)
		{
			float n = rand() % 20;
			arr.push(n);
			auto ar=arr._Get_container();
			//system("cls");
			for (int i = 0; i < it; i++)
			{
				cout << ar[i] << endl;
			}
			if (it != 9)
			{
				it++;
			}
			else
			{
				it = 9;
			}
			curr++;
			if(arr.size()==size)
			{
				buff.push(pop());
				i--;
				if (buff.isfull())
				{
					buff.print();
					break;
				}
			}
		}
		/*cout << "kont" << endl;
		for (int i = 0; i < size; i++)
		{
 			float po = rand() % 20;
			arr[i] = po;
			cout << arr[i] << endl;
			curr++;
 			if (curr == size)
			{
				Buffer buff;
				buff.push(pop());
				i--;
				curr == size;
				if (buff.isfull())
				{
					cout << "ther is no space" << endl;
					break;
				}

			}
		}*/
	}
	void push(float n)
	{
		arr.push(n);
		curr++;
	}
	float  pop()
	{
		int a= arr.front();
		arr.pop();
		return a;
	}
	/*float pop()
	{
		float *tmp = new float[size];
  		float var = arr[size - 1];
		for (int i = 0; i < size-1; i++)
		{
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
		return var;
	}*/
};


int main()
{
	srand(time(NULL));	
	Buffer buff(1);
	Kont kont;

}


