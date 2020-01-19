#include <cstdint>
#ifndef CONSTANT_VALUE_H
#define CONSTANT_VALUE_H

// 定义文件类型etype的可能取值
const uint16_t  ET_NONE     = 0;        // 未知目标文件格式
const uint16_t  ET_REL      = 1;        // 可重定位文件
const uint16_t  ET_EXEC     = 2;        // 可执行文件
const uint16_t  ET_DYN      = 3;        // 动态共享目标文件
const uint16_t  ET_CORE     = 4;        // core文件，内存崩溃时其内存映像的存储格式
const uint16_t  ET_LOPROC   = 0xff00;   // 特定处理器文件的扩展下边界
const uint16_t  ET_HIPROC   = 0xffff;   // 特定处理器文件的扩展上边界

// 定义emachine的可能取值
const uint16_t  EM_NONE     = 0;        // 未指定
const uint16_t  EM_M32      = 1;        // AT&T WE 
const uint16_t  EM_SPARC    = 2;        // SPARC
const uint16_t  EM_386      = 3;        // intel 80386
const uint16_t  EM_68K      = 4;        // Motorola 68000
const uint16_t  EM_88K      = 5;        // Motorola 88000
const uint16_t  EM_860      = 7;        // Intel 80860
const uint16_t  EM_MIPS     = 8;        // MIPS RS3000

// 程序头表中的p_type
const uint32_t  PT_NULL     = 0;        // 忽略
const uint32_t  PT_LOAD     = 1;        // 可加装程序段
const uint32_t  PT_DYNAMIC  = 2;        // 动态链接信息
const uint32_t  PT_INTERP   = 3;        // 动态加载器名称
const uint32_t  PT_NOTE     = 4;        // 一些辅助的附加信息
const uint32_t  PT_SHLIB    = 5;        // 保留
const uint32_t  PT_PHDR     = 6;        // 程序头表
// 预留给处理器使用
const uint32_t  PT_LOPROC   = 0x7000000;
const uint32_t  PT_HIPROC   = 0x7ffffff;

// p_flags取值
const uint32_t  PF_X        = 1;            // 本段具有可执行权限  
const uint32_t  PF_W        = 2;            // 本段具有可写权限
const uint32_t  PF_R        = 4;            // 本段具有可读权限
const uint32_t  PF_MASKOS   = 0x0ff00000;   // 本段与操作系统有关
const uint32_t  PF_MASKPROC = 0xf0000000;   // 本段与处理器有关

#endif