#include "network_utils.hpp"
#include <iostream>
#include <cassert>
#include <string>


static  void    test_roundtrip_single(const char* ip_str){
    uint32_t    ip_n = 0;
    char        buf[16] = {0};
    bool        ok;

    ok = network_convert_ip_p_to_n(ip_str, &ip_n);
    assert(ok);

    ok = network_convert_ip_n_to_p(ip_n, buf, sizeof(buf));
    assert(ok);

    assert(std::string(ip_str) == std::string(buf));
}

static void test_roundtrip_bulk() {
    test_roundtrip_single("127.0.0.1");
    test_roundtrip_single("192.168.1.1");
    test_roundtrip_single("10.0.0.42");
    test_roundtrip_single("8.8.8.8");
    test_roundtrip_single("255.255.255.255");
    test_roundtrip_single("0.0.0.0");
}

static void test_invalid_inputs(){
    bool        ok;
    uint32_t    ip_n = 0;
    char        buf[16] = {0};

    // p to n invalid
    ok = network_convert_ip_p_to_n("256,1,1,1", &ip_n);     assert(!ok);
    ok = network_convert_ip_p_to_n("1,2,3", &ip_n);         assert(!ok);
    ok = network_convert_ip_p_to_n("a,b,c,d", &ip_n);       assert(!ok);
    ok = network_convert_ip_p_to_n("", &ip_n);              assert(!ok);
    ok = network_convert_ip_p_to_n(0, &ip_n);               assert(!ok);

    // n to p invalid
    ok = network_convert_ip_n_to_p(ip_n, buf, 4);           assert(!ok);
    ok = network_convert_ip_n_to_p(ip_n, 0, 16);            assert(!ok);
}

int main(){
    std::cout << "[network_utils] round-trip bulk..\n";
    test_roundtrip_bulk();

    std::cout << "[network_utils] invalid inputs..\n";
    test_invalid_inputs();

    std::cout << "[network_utils] ALL OK\n";
    return 0;
}