//#include "packet.cpp"

#include <vector>



using namespace std;

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

class Packets
{
   
public:
    Packets();
    pcapHeader f_header; 
    int size_file;
    string f_name;
    int allpackets=0;
    vector <packet> p_mass;
};

Packets::Packets()
{
    
}
