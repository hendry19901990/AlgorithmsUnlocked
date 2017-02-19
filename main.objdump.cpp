main.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:   55                      push   rbp
   1:   53                      push   rbx
   2:   48 83 ec 58             sub    rsp,0x58
   6:   48 8d ac 24 80 00 00    lea    rbp,[rsp+0x80]
   d:   00
   e:   0f 29 75 b0             movaps XMMWORD PTR [rbp-0x50],xmm6
  12:   0f 29 7d c0             movaps XMMWORD PTR [rbp-0x40],xmm7
  16:   e8 00 00 00 00          call   1b <main+0x1b>
  1b:   66 0f ef c0             pxor   xmm0,xmm0
  1f:   f2 0f 11 45 a0          movsd  QWORD PTR [rbp-0x60],xmm0
  24:   48 8d 15 00 00 00 00    lea    rdx,[rip+0x0]        # 2b <main+0x2b>
  2b:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 32 <main+0x32>
  32:   e8 00 00 00 00          call   37 <main+0x37>
  37:   48 8d 45 a8             lea    rax,[rbp-0x58]
  3b:   48 89 c2                mov    rdx,rax
  3e:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 45 <main+0x45>
  45:   e8 00 00 00 00          call   4a <main+0x4a>
  4a:   48 8b 15 00 00 00 00    mov    rdx,QWORD PTR [rip+0x0]        # 51 <main+0x51>
  51:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 58 <main+0x58>
  58:   e8 00 00 00 00          call   5d <main+0x5d>
  5d:   48 8d 15 28 00 00 00    lea    rdx,[rip+0x28]        # 8c <main+0x8c>
  64:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 6b <main+0x6b>
  6b:   e8 00 00 00 00          call   70 <main+0x70>
  70:   48 8d 45 a0             lea    rax,[rbp-0x60]
  74:   48 89 c2                mov    rdx,rax
  77:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 7e <main+0x7e>
  7e:   e8 00 00 00 00          call   83 <main+0x83>
  83:   48 8b 15 00 00 00 00    mov    rdx,QWORD PTR [rip+0x0]        # 8a <main+0x8a>
  8a:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 91 <main+0x91>
  91:   e8 00 00 00 00          call   96 <main+0x96>
  96:   f2 0f 10 45 a0          movsd  xmm0,QWORD PTR [rbp-0x60]
  9b:   48 8b 45 a8             mov    rax,QWORD PTR [rbp-0x58]
  9f:   66 0f 28 c8             movapd xmm1,xmm0
  a3:   66 48 0f 6e c0          movq   xmm0,rax
  a8:   e8 c4 00 00 00          call   171 <_Z8multiplydd>
  ad:   66 48 0f 7e c3          movq   rbx,xmm0
  b2:   f2 0f 10 75 a0          movsd  xmm6,QWORD PTR [rbp-0x60]
  b7:   f2 0f 10 7d a8          movsd  xmm7,QWORD PTR [rbp-0x58]
  bc:   48 8d 15 4b 00 00 00    lea    rdx,[rip+0x4b]        # 10e <main+0x10e>
  c3:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # ca <main+0xca>
  ca:   e8 00 00 00 00          call   cf <main+0xcf>
  cf:   66 0f 28 cf             movapd xmm1,xmm7
  d3:   48 89 c1                mov    rcx,rax
  d6:   e8 00 00 00 00          call   db <main+0xdb>
  db:   48 8d 15 62 00 00 00    lea    rdx,[rip+0x62]        # 144 <main+0x144>
  e2:   48 89 c1                mov    rcx,rax
  e5:   e8 00 00 00 00          call   ea <main+0xea>
  ea:   48 89 c1                mov    rcx,rax
  ed:   48 8d 45 a8             lea    rax,[rbp-0x58]
  f1:   48 89 c2                mov    rdx,rax
  f4:   e8 00 00 00 00          call   f9 <main+0xf9>
  f9:   48 8d 15 6e 00 00 00    lea    rdx,[rip+0x6e]        # 16e <main+0x16e>
 100:   48 89 c1                mov    rcx,rax
 103:   e8 00 00 00 00          call   108 <main+0x108>
 108:   66 0f 28 ce             movapd xmm1,xmm6
 10c:   48 89 c1                mov    rcx,rax
 10f:   e8 00 00 00 00          call   114 <main+0x114>
 114:   48 8d 15 62 00 00 00    lea    rdx,[rip+0x62]        # 17d <_Z8multiplydd+0xc>
 11b:   48 89 c1                mov    rcx,rax
 11e:   e8 00 00 00 00          call   123 <main+0x123>
 123:   48 89 c1                mov    rcx,rax
 126:   48 8d 45 a0             lea    rax,[rbp-0x60]
 12a:   48 89 c2                mov    rdx,rax
 12d:   e8 00 00 00 00          call   132 <main+0x132>
 132:   48 8d 15 72 00 00 00    lea    rdx,[rip+0x72]        # 1ab <_Z8multiplydd+0x3a>
 139:   48 89 c1                mov    rcx,rax
 13c:   e8 00 00 00 00          call   141 <main+0x141>
 141:   66 48 0f 6e cb          movq   xmm1,rbx
 146:   48 89 c1                mov    rcx,rax
 149:   e8 00 00 00 00          call   14e <main+0x14e>
 14e:   48 8b 15 00 00 00 00    mov    rdx,QWORD PTR [rip+0x0]        # 155 <main+0x155>
 155:   48 89 c1                mov    rcx,rax
 158:   e8 00 00 00 00          call   15d <main+0x15d>
 15d:   b8 00 00 00 00          mov    eax,0x0
 162:   0f 28 75 b0             movaps xmm6,XMMWORD PTR [rbp-0x50]
 166:   0f 28 7d c0             movaps xmm7,XMMWORD PTR [rbp-0x40]
 16a:   48 83 c4 58             add    rsp,0x58
 16e:   5b                      pop    rbx
 16f:   5d                      pop    rbp
 170:   c3                      ret

0000000000000171 <_Z8multiplydd>:
 171:   55                      push   rbp
 172:   48 89 e5                mov    rbp,rsp
 175:   48 83 ec 30             sub    rsp,0x30
 179:   f2 0f 11 45 10          movsd  QWORD PTR [rbp+0x10],xmm0
 17e:   f2 0f 11 4d 18          movsd  QWORD PTR [rbp+0x18],xmm1
 183:   66 0f ef c0             pxor   xmm0,xmm0
 187:   f2 0f 11 45 f0          movsd  QWORD PTR [rbp-0x10],xmm0
 18c:   c7 45 fc 00 00 00 00    mov    DWORD PTR [rbp-0x4],0x0
 193:   66 0f ef c0             pxor   xmm0,xmm0
 197:   f2 0f 2a 45 fc          cvtsi2sd xmm0,DWORD PTR [rbp-0x4]
 19c:   f2 0f 10 4d 18          movsd  xmm1,QWORD PTR [rbp+0x18]
 1a1:   66 0f 2e c8             ucomisd xmm1,xmm0
 1a5:   76 15                   jbe    1bc <_Z8multiplydd+0x4b>
 1a7:   f2 0f 10 45 f0          movsd  xmm0,QWORD PTR [rbp-0x10]
 1ac:   f2 0f 58 45 10          addsd  xmm0,QWORD PTR [rbp+0x10]
 1b1:   f2 0f 11 45 f0          movsd  QWORD PTR [rbp-0x10],xmm0
 1b6:   83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
 1ba:   eb d7                   jmp    193 <_Z8multiplydd+0x22>
 1bc:   48 8d 15 76 00 00 00    lea    rdx,[rip+0x76]        # 239 <_Z41__static_initialization_and_destruction_0ii+0x1c>
 1c3:   48 8b 0d 00 00 00 00    mov    rcx,QWORD PTR [rip+0x0]        # 1ca <_Z8multiplydd+0x59>
 1ca:   e8 00 00 00 00          call   1cf <_Z8multiplydd+0x5e>
 1cf:   48 89 c1                mov    rcx,rax
 1d2:   48 8d 45 f0             lea    rax,[rbp-0x10]
 1d6:   48 89 c2                mov    rdx,rax
 1d9:   e8 00 00 00 00          call   1de <_Z8multiplydd+0x6d>
 1de:   48 8d 15 72 00 00 00    lea    rdx,[rip+0x72]        # 257 <_Z41__static_initialization_and_destruction_0ii+0x3a>
 1e5:   48 89 c1                mov    rcx,rax
 1e8:   e8 00 00 00 00          call   1ed <_Z8multiplydd+0x7c>
 1ed:   f2 0f 10 45 f0          movsd  xmm0,QWORD PTR [rbp-0x10]
 1f2:   66 48 0f 7e c0          movq   rax,xmm0
 1f7:   66 48 0f 6e c0          movq   xmm0,rax
 1fc:   48 83 c4 30             add    rsp,0x30
 200:   5d                      pop    rbp
 201:   c3                      ret

0000000000000202 <__tcf_0>:
 202:   55                      push   rbp
 203:   48 89 e5                mov    rbp,rsp
 206:   48 83 ec 20             sub    rsp,0x20
 20a:   48 8d 0d 00 00 00 00    lea    rcx,[rip+0x0]        # 211 <__tcf_0+0xf>
 211:   e8 00 00 00 00          call   216 <__tcf_0+0x14>
 216:   90                      nop
 217:   48 83 c4 20             add    rsp,0x20
 21b:   5d                      pop    rbp
 21c:   c3                      ret

000000000000021d <_Z41__static_initialization_and_destruction_0ii>:
 21d:   55                      push   rbp
 21e:   48 89 e5                mov    rbp,rsp
 221:   48 83 ec 20             sub    rsp,0x20
 225:   89 4d 10                mov    DWORD PTR [rbp+0x10],ecx
 228:   89 55 18                mov    DWORD PTR [rbp+0x18],edx
 22b:   83 7d 10 01             cmp    DWORD PTR [rbp+0x10],0x1
 22f:   75 21                   jne    252 <_Z41__static_initialization_and_destruction_0ii+0x35>
 231:   81 7d 18 ff ff 00 00    cmp    DWORD PTR [rbp+0x18],0xffff
 238:   75 18                   jne    252 <_Z41__static_initialization_and_destruction_0ii+0x35>
 23a:   48 8d 0d 00 00 00 00    lea    rcx,[rip+0x0]        # 241 <_Z41__static_initialization_and_destruction_0ii+0x24>
 241:   e8 00 00 00 00          call   246 <_Z41__static_initialization_and_destruction_0ii+0x29>
 246:   48 8d 0d b5 ff ff ff    lea    rcx,[rip+0xffffffffffffffb5]        # 202 <__tcf_0>
 24d:   e8 00 00 00 00          call   252 <_Z41__static_initialization_and_destruction_0ii+0x35>
 252:   90                      nop
 253:   48 83 c4 20             add    rsp,0x20
 257:   5d                      pop    rbp
 258:   c3                      ret

0000000000000259 <_GLOBAL__sub_I_main>:
 259:   55                      push   rbp
 25a:   48 89 e5                mov    rbp,rsp
 25d:   48 83 ec 20             sub    rsp,0x20
 261:   ba ff ff 00 00          mov    edx,0xffff
 266:   b9 01 00 00 00          mov    ecx,0x1
 26b:   e8 ad ff ff ff          call   21d <_Z41__static_initialization_and_destruction_0ii>
 270:   90                      nop
 271:   48 83 c4 20             add    rsp,0x20
 275:   5d                      pop    rbp
 276:   c3                      ret
 277:   90                      nop
 278:   90                      nop
 279:   90                      nop
 27a:   90                      nop
 27b:   90                      nop
 27c:   90                      nop
 27d:   90                      nop
 27e:   90                      nop
 27f:   90                      nop