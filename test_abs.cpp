#include <iostream>

bool checkData(int a)
{
  if (a == 0)
  {
    std::cout << "check failed" << std::endl;
  }
  else
  {
    std::cout << "check successfully" << std::endl;
  }
}

int main(void)
{
  int data = getchar();
  checkData(data);
  return 0;
}

// -O0
// test_abs:     file format elf64-x86-64


// Disassembly of section .text:

// 0000000000000000 <_Z8isBiggerii>:
//    0:   f3 0f 1e fa             endbr64 
//    4:   55                      push   %rbp
//    5:   48 89 e5                mov    %rsp,%rbp
//    8:   48 83 ec 10             sub    $0x10,%rsp
//    c:   89 7d fc                mov    %edi,-0x4(%rbp)
//    f:   89 75 f8                mov    %esi,-0x8(%rbp)
//   12:   48 8d 35 00 00 00 00    lea    0x0(%rip),%rsi        # 19 <_Z8isBiggerii+0x19>
//   19:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 20 <_Z8isBiggerii+0x20>
//   20:   e8 00 00 00 00          callq  25 <_Z8isBiggerii+0x25>
//   25:   48 89 c2                mov    %rax,%rdx
//   28:   8b 45 fc                mov    -0x4(%rbp),%eax
//   2b:   3b 45 f8                cmp    -0x8(%rbp),%eax
//   2e:   0f 9f c0                setg   %al
//   31:   0f b6 c0                movzbl %al,%eax
//   34:   89 c6                   mov    %eax,%esi
//   36:   48 89 d7                mov    %rdx,%rdi
//   39:   e8 00 00 00 00          callq  3e <_Z8isBiggerii+0x3e>
//   3e:   48 89 c2                mov    %rax,%rdx
//   41:   48 8b 05 00 00 00 00    mov    0x0(%rip),%rax        # 48 <_Z8isBiggerii+0x48>
//   48:   48 89 c6                mov    %rax,%rsi
//   4b:   48 89 d7                mov    %rdx,%rdi
//   4e:   e8 00 00 00 00          callq  53 <_Z8isBiggerii+0x53>
//   53:   90                      nop
//   54:   c9                      leaveq 
//   55:   c3                      retq   

// 0000000000000056 <main>:
//   56:   f3 0f 1e fa             endbr64 
//   5a:   55                      push   %rbp
//   5b:   48 89 e5                mov    %rsp,%rbp
//   5e:   be 06 00 00 00          mov    $0x6,%esi
//   63:   bf 05 00 00 00          mov    $0x5,%edi
//   68:   e8 00 00 00 00          callq  6d <main+0x17>
//   6d:   b8 00 00 00 00          mov    $0x0,%eax
//   72:   5d                      pop    %rbp
//   73:   c3                      retq   

// 0000000000000074 <_Z41__static_initialization_and_destruction_0ii>:
//   74:   f3 0f 1e fa             endbr64 
//   78:   55                      push   %rbp
//   79:   48 89 e5                mov    %rsp,%rbp
//   7c:   48 83 ec 10             sub    $0x10,%rsp
//   80:   89 7d fc                mov    %edi,-0x4(%rbp)
//   83:   89 75 f8                mov    %esi,-0x8(%rbp)
//   86:   83 7d fc 01             cmpl   $0x1,-0x4(%rbp)
//   8a:   75 32                   jne    be <_Z41__static_initialization_and_destruction_0ii+0x4a>
//   8c:   81 7d f8 ff ff 00 00    cmpl   $0xffff,-0x8(%rbp)
//   93:   75 29                   jne    be <_Z41__static_initialization_and_destruction_0ii+0x4a>
//   95:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 9c <_Z41__static_initialization_and_destruction_0ii+0x28>
//   9c:   e8 00 00 00 00          callq  a1 <_Z41__static_initialization_and_destruction_0ii+0x2d>
//   a1:   48 8d 15 00 00 00 00    lea    0x0(%rip),%rdx        # a8 <_Z41__static_initialization_and_destruction_0ii+0x34>
//   a8:   48 8d 35 00 00 00 00    lea    0x0(%rip),%rsi        # af <_Z41__static_initialization_and_destruction_0ii+0x3b>
//   af:   48 8b 05 00 00 00 00    mov    0x0(%rip),%rax        # b6 <_Z41__static_initialization_and_destruction_0ii+0x42>
//   b6:   48 89 c7                mov    %rax,%rdi
//   b9:   e8 00 00 00 00          callq  be <_Z41__static_initialization_and_destruction_0ii+0x4a>
//   be:   90                      nop
//   bf:   c9                      leaveq 
//   c0:   c3                      retq   

// 00000000000000c1 <_GLOBAL__sub_I__Z8isBiggerii>:
//   c1:   f3 0f 1e fa             endbr64 
//   c5:   55                      push   %rbp
//   c6:   48 89 e5                mov    %rsp,%rbp
//   c9:   be ff ff 00 00          mov    $0xffff,%esi
//   ce:   bf 01 00 00 00          mov    $0x1,%edi
//   d3:   e8 9c ff ff ff          callq  74 <_Z41__static_initialization_and_destruction_0ii>
//   d8:   5d                      pop    %rbp
//   d9:   c3                      retq 



// -O3
// test_abs:     file format elf64-x86-64


// Disassembly of section .text:

// 0000000000000000 <_Z8isBiggerii>:
//    0:   f3 0f 1e fa             endbr64 
//    4:   55                      push   %rbp
//    5:   ba 07 00 00 00          mov    $0x7,%edx
//    a:   89 fd                   mov    %edi,%ebp
//    c:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 13 <_Z8isBiggerii+0x13>
//   13:   53                      push   %rbx
//   14:   89 f3                   mov    %esi,%ebx
//   16:   48 8d 35 00 00 00 00    lea    0x0(%rip),%rsi        # 1d <_Z8isBiggerii+0x1d>
//   1d:   48 83 ec 08             sub    $0x8,%rsp
//   21:   e8 00 00 00 00          callq  26 <_Z8isBiggerii+0x26>
//   26:   31 f6                   xor    %esi,%esi
//   28:   39 dd                   cmp    %ebx,%ebp
//   2a:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 31 <_Z8isBiggerii+0x31>
//   31:   40 0f 9f c6             setg   %sil
//   35:   e8 00 00 00 00          callq  3a <_Z8isBiggerii+0x3a>
//   3a:   48 89 c7                mov    %rax,%rdi
//   3d:   e8 00 00 00 00          callq  42 <_GLOBAL__sub_I__Z8isBiggerii+0x22>

// Disassembly of section .text.startup:

// 0000000000000000 <main>:
//    0:   f3 0f 1e fa             endbr64 
//    4:   50                      push   %rax
//    5:   58                      pop    %rax
//    6:   be 06 00 00 00          mov    $0x6,%esi
//    b:   bf 05 00 00 00          mov    $0x5,%edi
//   10:   48 83 ec 08             sub    $0x8,%rsp
//   14:   e8 00 00 00 00          callq  19 <main+0x19>
//   19:   0f 1f 80 00 00 00 00    nopl   0x0(%rax)

// 0000000000000020 <_GLOBAL__sub_I__Z8isBiggerii>:
//   20:   f3 0f 1e fa             endbr64 
//   24:   48 83 ec 08             sub    $0x8,%rsp
//   28:   48 8d 3d 00 00 00 00    lea    0x0(%rip),%rdi        # 2f <_GLOBAL__sub_I__Z8isBiggerii+0xf>
//   2f:   e8 00 00 00 00          callq  34 <_GLOBAL__sub_I__Z8isBiggerii+0x14>
//   34:   48 8b 3d 00 00 00 00    mov    0x0(%rip),%rdi        # 3b <_GLOBAL__sub_I__Z8isBiggerii+0x1b>
//   3b:   48 83 c4 08             add    $0x8,%rsp
//   3f:   48 8d 15 00 00 00 00    lea    0x0(%rip),%rdx        # 46 <_GLOBAL__sub_I__Z8isBiggerii+0x26>
//   46:   48 8d 35 00 00 00 00    lea    0x0(%rip),%rsi        # 4d <_GLOBAL__sub_I__Z8isBiggerii+0x2d>
//   4d:   e9 00 00 00 00          jmpq   52 <_GLOBAL__sub_I__Z8isBiggerii+0x32>