#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "pcolparse.h"

// done
extern ip_hdr get_ip_details(FILE *f) {
    // precondition: at the start of an ip packet
    // postcondition: still at the same start of an ip packet
    ip_hdr hdr;
    int back_ptr = ftell(f);
    
    fread(&hdr.ip_header_length, 1, 1, f);
    // remove version
    hdr.ip_header_length = hdr.ip_header_length & 0x0F;
    
    // first_ip_packet_length
    fseek(f, 1, SEEK_CUR);
    fread(&hdr.ip_packet_length, 2, 1, f);
    // network to host byte order for shorts
    hdr.ip_packet_length = ntohs(hdr.ip_packet_length);

    // src_ip_add
    fseek(f, 8, SEEK_CUR);
    fread(&hdr.src_ip_add, 1, 4, f);

    // dest_ip_add
    fread(&hdr.dest_ip_add, 1, 4, f);

    // jump to TCP header
    fseek(f, 4*hdr.ip_header_length, back_ptr);

    // read TCP header
    // first_tcp_header_size i.e. data offset
    fseek(f, 12, SEEK_CUR);
    fread(&hdr.tcp_header_size, 1, 1, f);
    // bit shift by 4 to remove the bits from reserved and follow big endian order
    hdr.tcp_header_size = hdr.tcp_header_size >> 4;
    
    hdr.data_length = hdr.ip_packet_length - 4 * (hdr.ip_header_length + hdr.tcp_header_size);
    // rewind
    fseek(f, back_ptr, SEEK_SET);
    return hdr;
}

// done
int next_ip(FILE *f) {
    // precondition: is at start of an ip packet
    // postcondition: is at the start of the next ip packet
    int back_ptr = ftell(f);
    unsigned short this_packet_length;
    fseek(f, 2, SEEK_CUR);
    fread(&this_packet_length, 2, 1, f);
    this_packet_length = ntohs(this_packet_length);
    if (feof(f) || ferror(f)) {
        // rewind
        fseek(f, back_ptr, SEEK_SET);
        return 0;
    }
    fseek(f, this_packet_length - 2, SEEK_CUR);
    return 1;
}

// done
int count_total_packets(FILE *f) {
    // precondition: is at some point in the file
    // postcondition: is still at the same point in the file
    int back_ptr = ftell(f);
    fseek(f, 0, SEEK_SET);
    int total_ip_packets = 0;
    while (1)
    {
        // go to next ip packet
        if (next_ip(f) == 0) {
            break;
        }
        // increment packets
        total_ip_packets++;
    }
    fseek(f, back_ptr, SEEK_SET);
    return total_ip_packets;
}




