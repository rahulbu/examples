//illustration of map
#include<iostream>
#include<map>
using namespace std;
unsigned int compute(unsigned int n)
{
    unsigned int i;
	for (i = 0; i <(INT_MAX/2); i++);
	unsigned int sum=1;
    for(i=0;i<n;i++)
        sum += i;
    return sum;
}

int main()
{
    map<unsigned int,unsigned int> m;
    unsigned int key, value;
	for (;;) {
		cout << "enter the value of the order(<100) : ";
		cin >> key;

		if (key > 100)
			return 0;
		map<unsigned int ,unsigned int>::iterator p;
        p=m.find(key);//find() returns an iterator
        if(p==m.end())
        {
            m.insert(pair<unsigned int,unsigned int>(key,value=compute(key))); //update the map
            cout<<"value : "<<value<<endl;
        }
        else
            cout<<"value : "<<p->second<<endl;
	}

	return 0;
}
