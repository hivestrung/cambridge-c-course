#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "pcolparse.h"

int main(int argc, char *argv[])
{
    FILE *f;

    if (argc != 2)
    {
        puts("Usage: summary <infile>");
        return 1;
    }

    // try to open log file
    if ((f = fopen(argv[1], "rb")) == 0)
    {
        perror("Input file not found");
        return 2;
    }
    

    ip_hdr hdr = get_ip_details(f);
    
    // count total_ip_packets
    int total_ip_packets = count_total_packets(f);

    printf("%d.%d.%d.%d %d.%d.%d.%d %d %d %d %d\n", hdr.src_ip_add[0], hdr.src_ip_add[1], hdr.src_ip_add[2], hdr.src_ip_add[3], hdr.dest_ip_add[0], hdr.dest_ip_add[1], hdr.dest_ip_add[2], hdr.dest_ip_add[3], hdr.ip_header_length, hdr.ip_packet_length, hdr.tcp_header_size, total_ip_packets);
    return 0;
}
