#include <stdlib.h>
#include <string.h>
//#include "glib.h"
#include <fstream>
#include <semaphore.h>

using namespace std;

class portal
{

public:
portal();
~portal();
void startSniff();

private:

 string name="/home/dribl/pr/vivod.log";

};

portal::portal()
{
  ofstream fon;
  fon.open(name);
  fon<<"\t\t\t\t"<<"This's a log file of programm!"<<endl;
  fon.close();
}

portal::~portal()
{

}

void portal::startSniff()
{
system("sudo tcpdump -i enp0s20f0u2 -w /home/dribl/pr/data.cap");
}



