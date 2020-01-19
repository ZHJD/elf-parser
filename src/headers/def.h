#include <cstdint>
#ifndef DEF_H 
#define DEF_H  


// 定义elf32位结构体
struct ELF32_HEADER_DEF 
{
    uint8_t     e_ident[16];    // 魔数何其它信息
    uint16_t    e_type;         // elf文件类型
    uint16_t    e_machine;      // 占用2字节，描述elf目标文件的体系结构类型
    uint32_t    e_version;      // 表示版本信息
    uint32_t    e_entry;        // 操作系统运行该程序时，移交的虚拟地址
    uint32_t    e_phoff;        // program header table 在文件中的偏移量，若没有，则为0
    uint32_t    e_shoff;        // section header table 在文件内的字节偏移量，若没有，则为0
    uint32_t    e_flags;        // 与处理器相关的标志
    uint16_t    e_ehsize;       // elf header 的大小
    uint16_t    e_phentsize;    // program header table中每个entry的大小
    uint16_t    e_phnum;        // program header table中每个entry的大小
    uint16_t    e_shentsize;    // section header table中每个条目的大小
    uint16_t    e_shnum;        // section header table中的个数
    uint16_t    e_shstrndx;     // string name table 在节头表中的索引
};

// 程序头表
struct ELF32_PHDR
{
    uint32_t    p_type;         // 指明程序中该段的类型
    uint32_t    p_offset;       // 本段在文件内的起始偏移字节
    uint32_t    p_vaddr;        // 本段在内存中的其实虚拟地址
    uint32_t    p_paddr;        // 仅用于与物理地址相关的系统
    uint32_t    p_filesz;       // 指明该段的大小
    uint32_t    p_memsz;        // 指明该段在内存中的大小
    uint32_t    p_flags;        // 与该段相关的标志（可执行，可写，可读等）
    uint32_t    p_align;        // 指明对齐方式, 0 : 对齐，1 ： 对齐
};
#endif