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

    // 本段偏移文件开头字节数
    uint32_t p_offset();

    // 本段开始的虚拟地址
    uint32_t p_vaddr();

    // 物理地址
    uint32_t p_paddr();

    // 本段在文件中的大小
    uint32_t p_filesz();

    // 本段在内存中的大小
    uint32_t p_memsz();

    // 与本段相关的标志
    std::string p_flags();
private:
    ELF32_PHDR elf32_phdr;
};
#endif