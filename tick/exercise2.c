#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>


int main(int argc, char *argv[]) {
    FILE *fin;
    
    if (argc != 2) {
        puts("Usage: summary <infile>");
        return 1;
    }
    
    // try to open log file
    if ((fin = fopen(argv[2], "rb")) == 0)
    {
        perror("Cannot find input file");
        return 2;
    }
    unsigned char src_ip_add[4], dest_ip_add[4];
    
    unsigned char first_ip_header_length;    // IHL, length of internet header in 32-bit words
    unsigned short int first_ip_packet_length; // total length, 2 bytes
    unsigned char first_tcp_header_size;            // data offset, in TCP
    int total_ip_packets = 0; // total num of ip packets in the trace
    
    // read IP header
    
    // first_ip_header_length
    // read first byte, first half is version, second half is IHL
    fread(&first_ip_header_length, 1, 1, fin);
    // remove version
    first_ip_header_length = first_ip_header_length & 0x0F;
    
    // first_ip_packet_length
    fseek(fin, 1, SEEK_CUR);
    fread(&first_ip_packet_length, 2, 1, fin);
    // network to host byte order for shorts
    first_ip_packet_length = ntohs(first_ip_packet_length);
    
    // src_ip_add
    fseek(fin, 12, SEEK_SET);
    fread(&src_ip_add, 1, 4, fin);
    
    // dest_ip_add
    fread(&dest_ip_add, 1, 4, fin);
    
    // jump to TCP header
    fseek(fin, 4 * first_ip_header_length, SEEK_SET);
    
    // read TCP header
    
    // first_tcp_header_size i.e. data offset
    fseek(fin, 12, SEEK_CUR);
    fread(&first_tcp_header_size, 1, 1, fin);
    // bit shift by 4 to remove the bits from reserved and follow big endian order
    first_tcp_header_size = first_tcp_header_size >> 4;
    
    // count total_ip_packets
    // go to start
    fseek(fin, 0, SEEK_SET);
    while(true) {
        unsigned short this_packet_length;
        fseek(fin, 2, SEEK_CUR);
        fread(&this_packet_length, 2, 1, fin);
        this_packet_length = ntohs(this_packet_length);
        if (feof(fin) || ferror(fin)){
            break;
        }
        total_ip_packets++;
    }
    printf("%d.%d.%d.%d %d.%d.%d.%d %d %d %d %d\n", src_ip_add[0], src_ip_add[1], src_ip_add[2], src_ip_add[3], dest_ip_add[0],dest_ip_add[1],dest_ip_add[2],dest_ip_add[3], first_ip_header_length, first_ip_packet_length, first_tcp_header_size, total_ip_packets);
    return 0;
}

