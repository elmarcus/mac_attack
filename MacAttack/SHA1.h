#include <cstdint>
#include <iostream>
#include <string>


class SHA1
{
public:
    SHA1();
    void update(const std::string &s);
    void update(std::istream &is);
    std::string final();
    static std::string from_file(const std::string &filename);
	void setDigest(uint32_t mac[]);

private:
    uint32_t digest[5];
    std::string buffer;
    uint64_t transforms;

};