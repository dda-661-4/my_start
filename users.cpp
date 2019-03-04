#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

string fName;
unsigned char *ptr;

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
  int port;      //get from php and then checking 
  string name;  //get from php and then checking
  string sourseIP; 
  string poc_data[1000]; 
  int packetici;
};

class Packets
{
public:
Packets();
~Packets();
  
   int pos;
   int quantityOfUsers;
  
   pcapHeader fHeader;
   
   void start();
   string razbor(int pos);
   void workMac(string str[],int a);
   string addData(unsigned char ch[],int a);
   void workData(string str[],string DATA[],int a);
   bool checkingPackets();
   void checkMac(); 
   user users[10000];
   bool getValidMac(string a,string mass[]);
   void blockMac(string s); 
   string getNormalMac(string s);
};


class header
{
public:
  pkt pHeader;
  unsigned char *m_data;
};

Packets ps;
   int us=1; 
  string str[10000];// array for mac`s packet
  string DATA[10000];//array for data`s packets  
  unsigned char ch[10000];

Packets :: Packets()
{
 fName="/home/dribl/pr/log_whatsapp.cap";
}

 Packets::~Packets()
{
}

void Packets::start()
{
  int begin=0;
  int en=0;
 string st;
 string dat;//data of the packets 
 int len_poc;//length of data
 header pk;
  ifstream fn;
   int y=0;

     fn.open(fName);
      if(fn.is_open())
      {
          fn.seekg(begin, fn.end);
          int p = fn.tellg();
          en=p;
          cout<<"Length of file"<<p<<endl;
          fn.seekg(begin,fn.beg);   
       
            fn.read((char*)&ps.fHeader,24);
            int allpackets=0;

              while(fn.tellg()<p)
              {
               fn.read((char*)&pk.pHeader,16);
               //fn.seekg(16);
               //pk.pHeader.len=pk.pHeader.len-16;
               pk.m_data= new unsigned char[pk.pHeader.caplen];
               len_poc=pk.pHeader.caplen;
                ptr=pk.m_data;
                pos=fn.tellg();
       
                 fn.read((char*)pk.m_data,pk.pHeader.len);
       
                 dat=addData(ptr,len_poc);
                 DATA[allpackets]=dat;
      
                 st=razbor(pos);//mac address
                 str[allpackets]=st;
        
                 allpackets++;
                 delete []pk.m_data;
                 y++;
                 }
                 workMac(str,allpackets);
                           workData(str,DATA,allpackets);
                 //fn.close();
             //checkMac();
       }
           
   else{
     cout<<"not open";
       } 
      
} 

string Packets::razbor(int pos)
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
    return str;     
}

void Packets::workMac(string str[],int allpackets)
{
   
  string st;
  int k=0;
  int pakets=0;
  
  string stroka[allpackets];
  
 for(int i=0;i<allpackets;i++)
   {
   stroka[i]=str[i];
   }
  
 for(int j=0;j<allpackets;j++)
 {
  pakets=0;
  if(stroka[j]!=" ")
   {
    st=stroka[j];
    ps.users[k].mac=st;
  
    pakets++;
   }
    else
   {
   continue;
   }
     for(int i =1;i<allpackets;i++)
     {
       if(stroka[i]==st&&stroka[i]!=" ")
        {
            stroka[i]=" ";
            pakets++;
         }
     }
    ps.users[k].packetici=pakets;
      k++;
  }
 // k++;
  //cout<<endl<<k;
 
  //cout<<endl<<endl<<ps.users[k].mac;
 quantityOfUsers=k;
 //cout<<endl<<endl<<k;
}

void Packets::workData(string str[],string DATA[],int allpackets)
{
  string st;
  int k=0;
  int b=0;

 for(int j=0;j<allpackets;j++)
 {
  b=0;
  if(str[j]!=" ")
   {
    st=str[j];
    ps.users[k].poc_data[b]=DATA[b];
      b++;
   }
      else
       {
        continue;
       }
     for(int i=1;i<allpackets;i++)
     {
       if(str[i]==st&&str[i]!=" ")
        {
             str[i]=" ";
                   //ps.users[k].pocket_data=new string[10000];
                  //  ps.users[k].pocket_data[b]=DATA[i];
             ps.users[k].poc_data[b]=DATA[i];
             b++;
        }
     }
    k++;
  }

//cout<<"mac:"<<ps.users[1].mac<<endl;
/*cout<<"quantity:"<<ps.users[1].packetici<<endl;
for(int i=0;i<ps.users[1].packetici;i++)
   {
    cout<<"N packet:"<<i<<endl<<"data:"<<endl<<ps.users[1].poc_data[i]<<endl;

   }*/
 //cout<<ps.users[0].mac<<endl<<ps.users[0].poc_data[1];

}

string Packets::addData(unsigned char ptr[],int len_poc)
{
  string str=""; 
  unsigned char y;
  stringstream stream;
  int z;
     for(int k=0;k<len_poc;k++)
      { 
        y=(unsigned char)ptr[k];
        z=(int)y;
        stream<<hex<<z;
      }
   str=stream.str();
 return str;
}

void Packets::checkMac()
{
 string file;
 string mass[100];
 bool massMac[100];
 int i=0;
 int h=0;
 file="/home/dribl/pr/users.txt";
 
   //ps.users[2].mac="000102030405";

  for(int i=0;i<100;i++)
   {
   massMac[i]=false;
   }

   ifstream fin;
   fin.open(file);
    if(fin.is_open())
      {
           while(fin)
            { 
              fin>>mass[i];
              i++;
            }  
           i--;
         for(int j=0;j<quantityOfUsers;j++)
          {
              file=ps.users[j].mac;
              massMac[j]=getValidMac(file,mass);
               {
                if(massMac[j]==false)//if mac  is not valid then block him
                 {  
                    string s=ps.users[j].mac;
                    blockMac(s);
                 }
               } 
          }
        }
    else
       {
         cout<<endl<<endl<<"not OPEN";
       }      
}

bool Packets::getValidMac(string file,string mass[])
{
           for(int j=0;j<quantityOfUsers;j++)
            {
             if(mass[j]==file)
              {
                  return true; 
              }
            }
     return false;
}

void Packets::blockMac(string s)
{
   string c;
   c=getNormalMac(s);
   string a="/home/dribl/pr/wantedUsers.txt";//name of wantedusers
   ofstream fon;
   fon.open(a);
    if(fon.is_open())
     { 
        fon<<endl<<c;
         fon.close();
            /* a="/home/dribl/pr/vivod.log";
            fon.open(a);
              fon<<endl<<"the users "<<c<<" was deleted";
               fon.close();*/
         system("/home/dribl/pr/iptabl");
        
     }
    else
     { 
      cout<<"file wantedUsers is not open";
     }   
}

string Packets::getNormalMac(string s)
{
 string c="";
     for(int i=0;i<12;i++)
       {
        c=c+s[i];
           if(i==1||i==3||i==5||i==7||i==9)
             {
                c=c+":";
             }
       } 
    return c;
}
