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

class Snaky
{
    public:

        int longest(vector <string> snake);
};

int Snaky::longest ( vector <string> snake)
{
    vector <int> V;
    vector <int> V1;
    string s;
    string s1;
    int i,j,k;
    k = 1;
    int max, max1;
    int min;
    min = 0;
    max = 0;
    max1 =0;
    int len = 0;
    if ( snake.size() == 1)
    {
        s = snake[0];
        for ( j = 0; j < s.size()-1; j++)
        {
            if ( (s[j] == 'x') & (s[j+1] == 'x'))
            {

                k++;

                if ( k > max)
                {
                    max = k;
                }

            }
            else
            {
                k = 1;
            }
        }
        return ( max);
    }
    else
    {
        for (i =0; i < snake.size(); i++ )
        {
            s = snake[i];
            if ( s.size() > min)
            {
               min = s.size();
            }

            //  s1 = snake[i];
            for ( j = 0; j < s.size()-1; j++)
            {
                if ( (s[j] == 'x') & (s[j+1] == 'x'))
                {
                    k++;
                    if ( k > max)
                    {
                        max = k;
                    }
                }
                else
                {
                    k = 1;
                }
            }
         }   
                    V.assign(min, 1);
                    V1.assign(min, 1);
            for ( i = 1; i < snake.size();i++)
            {
                s = snake[i-1];
                s1 = snake[i];
                if ( s.size() > s1.size())
                {
                    len = s1.size();
                }
                else
                {
                    len = s.size();
                }
                for ( j = 0; j < len; j++)
                {
                    if( ( s[j] == 'x' ) & (s1[j] == 'x'))
                    {
                        V[j] = 1+V[j];
                        if(V[j] > V1[j])
                        {
                           V1[j] = V[j];
                        }
                    }
                    else
                    {
                        V[j] = 1;
                    }
              // cout << "V1[" << j << "]: " << V1[j] << endl;
                }
            }
        sort(V1.begin(), V1.end());
        max1 = V1[V1.size()-1];
        // cout << "Max1: " << max1 << endl;
// for (std::vector<int>::iterator it=V1.begin(); it!=V1.end(); ++it)
// {
 //    std::cout << ' ' << *it;
  //     std::cout << '\n'; }
    if ( max > max1)
    {
        return(max);
    }
    else
    {
        return (max1);
    }
    }
}


// Powered by FileEdit
