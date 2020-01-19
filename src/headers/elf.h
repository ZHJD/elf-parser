#include <fstream>
#include <string>
#include <vector>
#include "def.h"


class Elf32_header
{
public:
    // 读取elf文件头
    Elf32_header(const std::string& file_name);
    
    // 读取elf header
    void read_elf_header();

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
    
    // 返回program header table中entry个数
    int pht_entry_num();

    // 读取程序头表
    void read_elf_pht();

    // 打印program header table
    void print_pht();
private:
    // elf文件对象
    std::ifstream               elf_stream;
    // 存储elf头
    ELF32_HEADER_DEF            elf32_header_def;
    // 存储程序头表
    std::vector<ELF32_PHDR>     program_headers;
};


