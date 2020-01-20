typedef unsigned short int us_int;
typedef struct ip_add
{
    unsigned char x[4];
} ip_add;

typedef struct ip_hdr {
    u_char src_ip_add[4];
    u_char dest_ip_add[4];
    u_char ip_header_length;
    us_int ip_packet_length;
    u_char tcp_header_size;
} ip_hdr;


ip_hdr get_ip_details(FILE* f);


int get_data(FILE *f, char *bytes);

int next_ip(FILE *f);

int count_total_packets(FILE* f);








