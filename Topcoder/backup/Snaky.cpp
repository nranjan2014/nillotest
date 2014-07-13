#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define VIT(i, v) for (i = 0; i < v.size(); i++) 
#define IT(it, ds) for (it = ds.begin(); it != ds.end(); it++)
#define FUP(i, n) for (i = 0; i < n; i++)

#define O1(v) cout << v << endl
#define O2(v1, v2) cout << v1 << " " << v2 << endl
#define O3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << endl
#define OVEC(v) { int iii; VIT(iii, v) cout << v[iii] << " " ; cout << endl; }



class Snaky
{
    public:
    
        int longest(vector <string> snake);
    
};

int Snaky::longest ( vector <string> snake)
{
    
    string s;
    string s1;
    int i,j,k,l;
    k = 1;
    l = 1;
    int max, max1;
    max = 0;
    max1 =0;
    for (i =1; i< snake.size(); i++ )
    {
        s = snake[i-1];
        s1 = snake[i];
       // cout << "String " << i << " " << s << " string " << i+1 << " " << s1 << endl;
       // cout << " S size: " << s.length() << " S1 size: " << s1.length() << endl;
        for ( j = 0; j < s.size()-1; j++)
             {
                // cout << "char " << s[j] << " char " << s[j+1] << endl;
                 if ( (s[j] == 'x') & (s[j+1] == 'x'))
                 {
                     //start = j;
                     k++;
                     //cout << "char " << s[j] << " char " << s[j+1] << endl;
                     if ( k > max)
                     {
                       max = k;
                     }
                     
                 }
                 else
                 {
                     k = 1;
                 }
                     if( ( s[j] == 'x' ) & (s1[j] == 'x'))
                     {
                         l++;
                     
                         if ( l > max1)
                         {
                             max1 = l;
                         }
                     }
                 else
                 {
                     l = 1;
                 }
                  
             }
    }
                     if ( max > max1)
                     {
                         return(max);
                     }
                     else
                     {
                         return (max1);
                     }
}
// Powered by FileEdit


// Powered by FileEdit
