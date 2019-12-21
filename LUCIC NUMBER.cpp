#include<iostream>
#include<vector>
#include<math.h>
#include<list>
#include<iterator>
#define ll long long int


using namespace std;
list<int> a;
list<int>::iterator it1,it2,it3;

void sieve()

{
    int ct=0;
    int n=9999997;
    a={1,2,3};
    for(int i=3;i<=n;i+=2)
    {
        if(i%2==0){;}
        else if(i%3==0){;}
        else {a.push_back(i);}
    }
    for(int index= 3;index<a.size();index++)
    {   it3 =a.begin();
        advance(it3,index);
        int remo= *it3 +index;
        while(remo<=a.size())
        {   it2= a.begin();
        advance(it2,remo);
            a.erase(it2);
            remo+= *it3;
        }
    }

   cout<<"abc";







}
int main()
{
    sieve();

}

