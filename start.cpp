#include <iostream>
#include "packet.cpp"
#include "Packets.cpp"
#include <mutex>
#include <chrono>
#include <thread>
#include "pcap.cpp"

class rulevoy
{
public:
    rulevoy();
    //void start();
};

using namespace std;

 void start();
 void shell();
 mutex m_t; 

int main()
{ 
    
    //rulevoy rul;
    //thread t2(shell);
   // thread t1(start);
    //t2.join();
   // t1.join();
    
    start();
   //rul.start();
    
    return 0;
}

rulevoy::rulevoy()
{}

void start()
{
    //m_t.lock();
   // this_thread::sleep_for(std::chrono::seconds(1));
    //packet p;
    // f_name=FileDialog::getOpenFileName(0,"open the     file","","(*.cap)");
    Packets ps;
    
    ps.f_name="/home/dribl/my_start/PINGGGGG"; // изменить выбор в ручную
    ifstream file;
    int a=0;
    file.open(ps.f_name);
    
    file.seekg(0,file.end);
    ps.size_file=file.tellg();
    file.seekg(0,file.beg);
    
    file.read((char*)&ps.f_header,24);
    //cout<<file.tellg();
    
    packet pac;
    
    
    unsigned char *arr;
    while(a<ps.size_file)
    {
    file.read((char*)&pac.pHeader,16);
      pac.pac_mass.reserve(pac.pHeader.len);
    arr= new unsigned char[pac.pHeader.len];
    
    file.read((char*)arr,pac.pHeader.len);
    pac.pac_mass.push_back(*arr);
    ps.p_mass.push_back(pac);
    ps.p_mass.reserve(ps.allpackets);
    
    ps.allpackets++;
    a=file.tellg();
    
    pac.razbor();
    delete arr;
    }
   cout<<ps.allpackets;
  //  m_t.unlock();
   // cout<<ps.p_mass[68].pHeader.caplen;
}

void shell()
{
    m_t.lock();
    pcap p;
    p.lookupdev();
    p.lookupnet();
    p.on_live();
    p.cap_next();
    m_t.unlock();
    
}

 //system("chmod 777 /home/dribl/my_start/shell");
  //  this_thread::sleep_for(std::chrono::seconds(1));
  //  system("echo Dimad19980617 | sudo -S /home/dribl/my_start/shell");
    //this_thread::sleep_for(std::chrono::seconds(3));




