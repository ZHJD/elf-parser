#include "def.h"
#include <string>

#ifndef ELF32_PHDR_PARSER
#define ELF32_PHDR_PARSER
// 解析program header table 
class Elf32_PHDR_parser
{
public:
    void set_phdr(ELF32_PHDR& _elf32_phdr);

    std::string p_type();
private:
    ELF32_PHDR elf32_phdr;
};
#endif