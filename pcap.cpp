#include <iostream>
#include <pcap.h>

using namespace std;

class pcap
{
public:
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 mask;  /* Сетевая маска */
    bpf_u_int32 net;
    struct pcap_pkthdr header; /* Заголовок который нам дает PCAP */
    const unsigned char *packet;
    
    pcap();
    void lookupdev();
    void lookupnet();
    void on_live();
    void cap_next();
};

pcap::pcap()
{}


void pcap::lookupdev()
{
 dev=pcap_lookupdev(errbuf);
    //cout<<dev;
}

void pcap::lookupnet()
{
    
 pcap_lookupnet(dev,&net,&mask,errbuf);
    cout<<dev<<endl<<net<<endl<<mask<<endl;
}

void pcap::on_live()
{
    handle= pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
}

void pcap::cap_next()
{
   //packet = pcap_next(handle, &header);
   // cout<<header.caplen<<endl<<header.len;
}


//struct pcap_pkthdr {
  //  struct timeval ts; /* Время захвата */
  //  bpf_u_int32 caplen; /* Длина заголовка */
  //  bpf_u_int32 len; /* Длина пакета */
//};
