#include "elf32_phdr_parser.h"
#include "constant_value.h"

void Elf32_PHDR_parser::set_phdr(ELF32_PHDR& _elf32_phdr)
{
    elf32_phdr = _elf32_phdr;
}

std::string Elf32_PHDR_parser::p_type()
{
    std::string ptype = "";
    switch (elf32_phdr.p_type)
    {
    case PT_NULL:
        ptype = "ignored !";
        break;
    case PT_LOAD:
        ptype = "loadable segment";
        break;
    case PT_DYNAMIC:
        ptype = "dynamic link information";
        break;
    case PT_INTERP:
        ptype = "dynamic loader name";
        break;
    case PT_NOTE:
        ptype = "noted information";
        break;
    case PT_SHLIB:
        ptype = "reserved information";
        break;
    case PT_PHDR:
        ptype = "program header table";
        break;
    default:
        ptype = "cpu related";
        break;
    }
    return ptype;
}

uint32_t Elf32_PHDR_parser::p_offset()
{
    return elf32_phdr.p_offset;
}

uint32_t Elf32_PHDR_parser::p_vaddr()
{
    return elf32_phdr.p_vaddr;
}

uint32_t Elf32_PHDR_parser::p_paddr()
{
    return elf32_phdr.p_paddr;
}

uint32_t Elf32_PHDR_parser::p_filesz()
{
    return elf32_phdr.p_filesz;
}

uint32_t Elf32_PHDR_parser::p_memsz()
{
    return elf32_phdr.p_memsz;
}

std::string Elf32_PHDR_parser::p_flags()
{
    std::string flags = "";
    switch (elf32_phdr.p_flags)
    {
    case PF_X:
        flags = "X";
        break;
    case PF_W:
        flags = "W";
        break;
    case PF_R:
        flags = "R";
    default:
        
        break;
    }
}