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

class Bigital {
public:
    double energy(string tStart, string tEnd);
};

int hhmmss_to_s(string hhmmss)
{
    int h, m, s;
    
    sscanf(hhmmss.c_str(), "%d:%d:%d", &h, &m, &s);
    return s + m*60 + h*3600;
}

string s_to_hhmmss(int s)
{
    int h, m;
    char buf[7];
    string rv;
    
    h = (s / 3600) % 12;
    if (h == 0) h = 12;
    m = (s / 60) % 60;
    s %= 60;
    sprintf(buf, "%02d%02d%02d", h, m, s);
    rv = buf;
    return rv;
}

double Bigital::energy(string tStart, string tEnd)
{
    int i, j, k;
    int ts, te;
    double v;
    string hhmmss;
    
    ts = hhmmss_to_s(tStart);
    te = hhmmss_to_s(tEnd);
    if (te < ts) te += 12*3600;
    
    v = 0;
    for (i = ts; i <= te; i++) {
        hhmmss = s_to_hhmmss(i);
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 4; k++) if ((hhmmss[j]-'0') & (1 << k)) v++;
        }
    }
    return v / 1000.0 / 3600.0 ;
}


// Powered by FileEdit
