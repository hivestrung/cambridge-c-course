#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "pcolparse.h"

int main(int argc, char *argv[])
{

    FILE *f;

    if (argc != 3)
    {
        puts("Usage: summary <infile> <outfile>");
        return 1;
    }

    if ((f = fopen(argv[1], "rb")) == 0)
    {
        perror("Input file not found");
        return 2;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL)
    {
        perror("Error opening out file");
        return 3;
    }

    for (;;)
    {
        ip_hdr hdr = get_ip_details(f);
        char bytes[hdr.data_length];
        // move to the right part
        fseek(f, 4*(hdr.ip_header_length+hdr.tcp_header_size), SEEK_CUR);
        if (fread(bytes, 1, hdr.data_length, f) < hdr.data_length) {
            break;
        } 
        fwrite(bytes, 1, hdr.data_length, fout);
    }
    fclose(fout);

    return 0;
}
