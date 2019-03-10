#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct pkt
{
        int t1;
        int t2;
        int caplen;
        int len;
};

class packet
{
public:
    packet();
    void razbor();
    void work_pack();
    
    vector <unsigned char> pac_mass;
    pkt pHeader;
    string mac;
};

packet::packet()
{
    
}

void packet::razbor()
{
   string str=""; 
 unsigned char y;
 stringstream stream;
 int z;
   
  for(int i=0;i<66;i++)
   {
     y=(unsigned char)pac_mass[i];
     z=(int)y;
     stream<<hex<<z;
   }

    str=stream.str();
    mac=str;
    cout<<mac<<endl<<pHeader.caplen<<endl;
 // cout<<pac_mass[];
  //us++;
}

void packet::work_pack()
{
    
}
// g++ start.cpp -o out.tuo -pthread -lpcap
