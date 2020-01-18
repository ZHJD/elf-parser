#include <cstdint>
#include <fstream>
#include <string>
#include "def.h"


class Elf32_header
{
public:
    // 读取elf文件头
    Elf32_header(std::ifstream& elf_stream);
    
    // 是否为elf文件
    bool isELF();

    // 打印elf文件信息
    void print_header();

    // 64 or 32
    // 32 返回1
    // 64 返回2
    int elf_class();

    // LSB : return 1
    // MSB : return 2
    int lsb_or_msb();

    // 版本信息
    int version_info();

    // 返回目标文件类型etype
    std::string elf_type();

    // 在哪种硬件平台上运行
    std::string elf_machine();
private:
    ELF32_HEADER_DEF elf32_header_def;
    

};

