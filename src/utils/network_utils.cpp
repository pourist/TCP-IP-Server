#include "network_utils.hpp"

#include <cstdio>
#include <arpa/inet.h>

bool network_convert_ip_n_to_p(uint32_t ip_network, char* out_buf, size_t out_len)
{
    if (!out_buf || out_len < 16)
        return (false);

    // Convert from network (big-endian) to host for easy byte extraction
    uint32_t ip_host = ntohl(ip_network);

    unsigned int A = (ip_host >> 24) & 0xFFu;
    unsigned int B = (ip_host >> 16) & 0xFFu;
    unsigned int C = (ip_host >> 8)  & 0xFFu;
    unsigned int D =  ip_host        & 0xFFu;

    // Ensure null-termination and size safety
    int n = std::snprintf(out_buf, out_len, "%u.%u.%u.%u", A, B, C, D);
    return (n > 0 && static_cast<size_t>(n) < out_len);
}

bool network_convert_ip_p_to_n(const char* ip_str, uint32_t* out_ip_network)
{
    if (!ip_str || !out_ip_network) return false;

    unsigned int A = 0, B = 0, C = 0, D = 0;
    if (std::sscanf(ip_str, "%u.%u.%u.%u", &A, &B, &C, &D) != 4) return false;
    if (A > 255u || B > 255u || C > 255u || D > 255u) return false;

    uint32_t ip_host = (A << 24) | (B << 16) | (C << 8) | D;
    *out_ip_network = htonl(ip_host);  // return in network byte order
    return true;
}
