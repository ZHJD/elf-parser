#include <iostream>
#include <fstream>
#include <cstdio>
#include "elf.h"
#include "constant_value.h"
#include "elf32_phdr_parser.h"




/******************************************************************/
Elf32_header::Elf32_header(const std::string& file_name)
{
    elf_stream.open(file_name, std::ifstream::binary);
}

void Elf32_header::read_elf_header()
{
    if(!elf_stream) 
    {
        throw "elf file is empty !";
    }
    else
    {
        // 数据读入elf——header结构体中
        elf_stream.read((char *)&elf32_header_def,
            sizeof(elf32_header_def));
    }
}

bool Elf32_header::isELF()
{
    if(elf32_header_def.e_ident[0] == 0x7f &&
        elf32_header_def.e_ident[1] == 0x45 &&
        elf32_header_def.e_ident[2] == 0x4c &&
        elf32_header_def.e_ident[3] == 0x46)
    {
        std::cout << "This is a elf file" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

int Elf32_header::elf_class()
{
    if(elf32_header_def.e_ident[4] == 0) 
    {
        throw "undefined file type !";
    }
    return elf32_header_def.e_ident[4];
}

int Elf32_header::lsb_or_msb()
{
    if(elf32_header_def.e_ident[5] == 0) 
    {
        throw "invaild encode format !";
    }
    return elf32_header_def.e_ident[5];
}

int Elf32_header::version_info()
{
    if(elf32_header_def.e_ident[6] == 0) 
    {
        throw "invaild elf version !";
    }
    return elf32_header_def.e_ident[6];
}

std::string Elf32_header::elf_type()
{
    std::string elftype_info = "";
    switch (elf32_header_def.e_type)
    {
    case ET_NONE:
        elftype_info = "undefined file format";
        break;
    case ET_REL:
        elftype_info = "relocate file";
        break;
    case ET_EXEC:
        elftype_info = "executable file";
        break;
    case ET_DYN:
        elftype_info = "dynamic shared object file";
        break;
    case ET_CORE:
        elftype_info = "core file";    
    default:
        break;
    }
    return elftype_info;
}

std::string Elf32_header::elf_machine()
{
    std::string machine_info = "";
    switch (elf32_header_def.e_machine)
    {
    case EM_NONE:
        machine_info = "undefined !";
        break;
    case EM_M32:
        machine_info = "AT&T WE 32100";
        break;
    case EM_SPARC:
        machine_info = "SPARC";
        break;
    case EM_386:
        machine_info = "Intel 80386";
        break;
    case EM_68K:
        machine_info = "Motorola 68000";
        break;
    case EM_88K:
        machine_info = "Motorola 88000";
        break;
    case EM_860:
        machine_info = "Intel 80860";
        break;
    case EM_MIPS:
        machine_info = "MIPS RS3000";
        break;
    default:
        break;
    }
    return machine_info;
}

void Elf32_header::print_header()
{
    printf("ELF Header:\n");
    printf("  Magic:\t");
    for(int i = 0; i < 16; i++) 
    {
        printf("  %02x", elf32_header_def.e_ident[i]);
    }
    printf("\n");
    if(elf_class() == 1) 
    {
        printf("%-2s%-35s%-20s\n", "", "Class:", "ELF32");
    }
    else 
    {
        printf("%-2s%-35s%-20s\n", "", "Class:", "ELF64");
    }
    if(lsb_or_msb() == 1)
    {
        printf("%-2s%-35s%-20s\n", "", "Data:", "little endian");
    }
    else
    {
        printf("%-2s%-35s%-20s\n", "", "Data:", "big endian");
    }
    if(version_info() == 1) 
    {
        printf("%-2s%-35s%-20s \n", "", "Version:", "1(current)");
    }
    printf("%-2s%-35s%-20s\n", "", "Type:", elf_type().c_str());
    printf("%-2s%-35s%-20s\n", "", "Machine:", elf_machine().c_str());
    printf("%-2s%-35s0x%010x\n", "", "Entry point address:", elf32_header_def.e_entry);
    printf("%-2s%-35s%2d\n", "", "Start of program headers:", elf32_header_def.e_phoff);
    printf("%-2s%-35s%2d(bytes)\n", "", "Size of program header:", elf32_header_def.e_phentsize);
    printf("%-2s%-35s%d\n", "", "Number of program headers:", elf32_header_def.e_phnum);
    printf("%-2s%-35s%2d\n", "", "Start of section headers:", elf32_header_def.e_shoff);
    printf("%-2s%-35s%2d(bytes)\n", "", "Size of section headers:", elf32_header_def.e_shentsize);
    printf("%-2s%-35s%d\n", "", "Number of section headers:", elf32_header_def.e_shnum);
    printf("%-2s%-35s%d\n", "", "Section header string table index:", elf32_header_def.e_shstrndx);
}

int Elf32_header::pht_entry_num()
{
    return elf32_header_def.e_phnum;
}

void Elf32_header::read_elf_pht()
{
    ELF32_PHDR elf_phdr;
    int phnum = pht_entry_num();;
    for(int i = 0; i < phnum; i++)
    {
        elf_stream.read((char *)&elf_phdr, sizeof(elf_phdr));
        program_headers.push_back(elf_phdr);
    }
}

void Elf32_header::print_pht()
{
    Elf32_PHDR_parser elf32_phdr_parser;
    printf("Program header table:\n");
    for(int i = 0; i < program_headers.size(); i++) 
    {
        elf32_phdr_parser.set_phdr(program_headers[i]);
        printf("program header %d\n", i);

    }
}

int main()
{   
    std::string file_name = "kernel.bin";
    Elf32_header header = Elf32_header(file_name);
    header.read_elf_header();
    header.print_header();

    header.read_elf_pht();
    header.print_pht();
    return 0;
}