#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

string fName;

struct pkt
{
        int t1;
        int t2;
        int caplen;
        int len;
};


struct pcapHeader
{
    int magic;
    int version_major;
    int version_minor;
    int thiszone;     /* gmt to local correction */
    int sigfigs;    /* accuracy of timestamps */
    int snaplen;    /* max length saved portion of each pkt */
    int linktype;   /* data link type (LINKTYPE_*) */
};

class user
{
public:
  string mac;
  int port;
  string name;  
  unsigned char data[1000000];
  int packetici;
};

class header
{
public:
  pkt pHeader;
  //unsigned char *m_data;
  unsigned char m_data[1000000];
};

class Packets
{
public:
Packets();
~Packets();
  
  int pos;
   pcapHeader fHeader;
   user users[10000];

   void start();
   void razbor(int pos);

};

   Packets ps;
   int us=0; 

Packets :: Packets()
{
string fName="/home/dribl/pr/skype.cap";
}

 Packets::~Packets()
{
}

void Packets::start()
{
  header pk;
  ifstream fn;
  fn.open(fName);
 
    fn.seekg(0, fn.end);
    int p = fn.tellg();
    cout<<"Length of file"<<p<<endl;
    fn.seekg(0,fn.beg);   

    fn.read((char*)&ps.fHeader,24);
     
    int allpackets=0;
 
   while(fn.tellg()<p)
     {
       fn.read((char*)&pk.pHeader,16);
       pos=fn.tellg();
       fn.read((char*)pk.m_data,pk.pHeader.len);
       allpackets++;
       razbor(pos);
     }
}

void Packets::razbor(int pos)
{
 pos=pos+6;
 ifstream fn;
 fn.open(fName);
 fn.seekg(pos);
 char s[6];
 fn.read(s,6);
 string str=""; 
 unsigned char y;
 stringstream stream;
 int z;
   
  for(int i=0;i<6;i++)
   {
     y=(unsigned char)s[i];
     z=(int)y;
     stream<<hex<<z;
   }

    str=stream.str();
    ps.users[us].mac=str;
  us++;
}










