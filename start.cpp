#include <iostream>
#include "packet.cpp"
#include "Packets.cpp"


class rulevoy
{
public:
    rulevoy();
    void start();
     
};

rulevoy::rulevoy()
{}

void rulevoy::start()
{
    //packet p;
    // f_name=FileDialog::getOpenFileName(0,"open the     file","","(*.cap)");
    Packets ps;
    
    ps.f_name="PINGGGGG"; // изменить выбор в ручную
    ifstream file;
    
    file.open(ps.f_name);
    file.read((char*)&ps.f_header,24);
    
    file.seekg (0, file.end);
    ps.size_file = file.tellg();
    file.seekg (0, file.beg);
    
    file.seekg(24);
      
    //cout<<file.tellg()<<endl;
    /*int m;
    packet *pac;
   // while(file.tellg()<ps.size_file)
    //{
        cout<<file.tellg()<<endl;
     pac=new packet;
     file.read((char*)&pac->pHeader,16);
     m=pac->pHeader.caplen-file.tellg();
     cout<<m<<endl;
     cout<<file.tellg()<<endl;
     file.read((char*)&pac->mass,m);
     cout<<file.tellg()<<"end"<<endl;
     delete pac;
     //cout<<pac->pHeader.caplen;
     //cout<<pac.mass[1];
 */
    
    
    //cout<<ps.size_file;
    // ps.mass[0]=
}


using namespace std;

int main()
{ 
    rulevoy rul;
    rul.start();
    return 0;
}



