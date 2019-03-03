#include <iostream>
#include <fstream>

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

    char mass[1000000];
    pkt pHeader;
  
};

packet::packet()
{
    
}

void packet::razbor()
{
    
}

void packet::work_pack()
{
    
}
