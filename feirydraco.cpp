
//hash table
#include<iostream>
#include<list>
#include<cstdlib>
using namespace std;
const int s = 10;

class req
{
public:
	unsigned long int key;
	unsigned long int val;
	req()
		{ key = -1; val = 0; }
	req(unsigned long int k,unsigned long int v)
	{
		key = k;
		val = v;
	}
};
class cache
{
	list<req> li;
	static unsigned long int ans;
public:
	bool check(unsigned long int key)
	{
		list<req>::iterator first = li.begin();
		while (first != li.end())
		{
			if (first->key == key) {
				ans = first->val;
				return true;
			}
			first++;
		}
		return false;
	}

	static void display()
	{
		cout <<ans<<endl;
	}

	void update(unsigned int key,unsigned int res)
	{
		li.push_back(req(key, res));
		cout << res << endl;
	}

};
unsigned long int cache::ans;
void delay()
{
	int i;
	for (i = 0; i <(INT_MAX/2); i++);
}
unsigned long int compute(const int n)
{
	int *a = new int[n*n], *b = new int[n*n], *c = new int[n*n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[(n*i)+j] = rand();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[(n*i)+j] = rand();
	unsigned long int sum=0;
	delay();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			c[(n*i) + j] = 0;
			for (int k = 0; k < n; k++)
				c[(n*i) + j] = a[(n*i) + k] + b[(n*k) + j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += c[(n*i) + j];
	return sum;
}

int main()
{
	cache arr[s];
	unsigned int key;
	for (;;) {
		cout << "enter the value of the order(<100) : ";
		cin >> key;

		if (key >= 100)
			return 0;
		if (arr[key%s].check(key))
			cache::display();
		else {
			arr[key%s].update(key, compute(key));
		}

	}

	return 0;
}
