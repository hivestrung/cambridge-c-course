#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "pcolparse.h"

ip_hdr get_ip_details(FILE *f) {
    ip_hdr hdr;
    
    fread(&hdr.ip_header_length, 1, 1, f);
    // remove version
    hdr.ip_header_length = hdr.ip_header_length & 0x0F;

    // first_ip_packet_length
    fseek(f, 1, SEEK_CUR);
    fread(&hdr.ip_packet_length, 2, 1, f);
    // network to host byte order for shorts
    hdr.ip_packet_length = ntohs(hdr.ip_packet_length);

    // src_ip_add
    fseek(f, 12, SEEK_SET);
    fread(&hdr.src_ip_add, 1, 4, f);

    // dest_ip_add
    fread(&hdr.dest_ip_add, 1, 4, f);

    // jump to TCP header
    fseek(f, 4 * hdr.ip_header_length, SEEK_SET);

    // read TCP header

    // first_tcp_header_size i.e. data offset
    fseek(f, 12, SEEK_CUR);
    fread(&hdr.tcp_header_size, 1, 1, f);
    // bit shift by 4 to remove the bits from reserved and follow big endian order
    hdr.tcp_header_size = hdr.tcp_header_size >> 4;
    
    return hdr;
}

int count_total_packets(FILE *fin) {
    fseek(fin, 0, SEEK_SET);
    int total_ip_packets = 0;
    while (1)
    {
        unsigned short this_packet_length;
        fseek(fin, 2, SEEK_CUR);
        fread(&this_packet_length, 2, 1, fin);
        this_packet_length = ntohs(this_packet_length);
        if (feof(fin) || ferror(fin))
        {
            break;
        }
        total_ip_packets++;
    }
    fseek(fin, 0, SEEK_SET);
    return total_ip_packets;
}

