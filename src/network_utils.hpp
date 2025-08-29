#ifndef NETWORK_UTILS_HPP
#define NETWORK_UTILS_HPP

#include <stdint.h>   // uint32_t
#include <cstddef>    // size_t

// Convert uint32_t IP in *network* byte order to "A.B.C.D".
// Writes into caller-provided buffer (>=16 bytes incl. '\0').
// Returns true on success.
bool network_convert_ip_n_to_p(uint32_t ip_network, char* out_buf, size_t out_len);

// Convert "A.B.C.D" to uint32_t in *network* byte order.
// Returns true on success and stores result in *out_ip_network.
bool network_convert_ip_p_to_n(const char* ip_str, uint32_t* out_ip_network);

#endif
