
main.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	e8 00 00 00 00       	callq  d <main+0xd>
   d:	48 8d 15 a4 00 00 00 	lea    0xa4(%rip),%rdx        # b8 <_ZNSt8__detailL19_S_invalid_state_idE+0x18>
  14:	48 8b 0d 00 00 00 00 	mov    0x0(%rip),%rcx        # 1b <main+0x1b>
  1b:	e8 00 00 00 00       	callq  20 <main+0x20>
  20:	ba ba 12 03 00       	mov    $0x312ba,%edx
  25:	48 89 c1             	mov    %rax,%rcx
  28:	e8 00 00 00 00       	callq  2d <main+0x2d>
  2d:	b8 00 00 00 00       	mov    $0x0,%eax
  32:	48 83 c4 20          	add    $0x20,%rsp
  36:	5d                   	pop    %rbp
  37:	c3                   	retq   

0000000000000038 <__tcf_0>:
  38:	55                   	push   %rbp
  39:	48 89 e5             	mov    %rsp,%rbp
  3c:	48 83 ec 20          	sub    $0x20,%rsp
  40:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 47 <__tcf_0+0xf>
  47:	e8 00 00 00 00       	callq  4c <__tcf_0+0x14>
  4c:	90                   	nop
  4d:	48 83 c4 20          	add    $0x20,%rsp
  51:	5d                   	pop    %rbp
  52:	c3                   	retq   

0000000000000053 <_Z41__static_initialization_and_destruction_0ii>:
  53:	55                   	push   %rbp
  54:	48 89 e5             	mov    %rsp,%rbp
  57:	48 83 ec 20          	sub    $0x20,%rsp
  5b:	89 4d 10             	mov    %ecx,0x10(%rbp)
  5e:	89 55 18             	mov    %edx,0x18(%rbp)
  61:	83 7d 10 01          	cmpl   $0x1,0x10(%rbp)
  65:	75 21                	jne    88 <_Z41__static_initialization_and_destruction_0ii+0x35>
  67:	81 7d 18 ff ff 00 00 	cmpl   $0xffff,0x18(%rbp)
  6e:	75 18                	jne    88 <_Z41__static_initialization_and_destruction_0ii+0x35>
  70:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 77 <_Z41__static_initialization_and_destruction_0ii+0x24>
  77:	e8 00 00 00 00       	callq  7c <_Z41__static_initialization_and_destruction_0ii+0x29>
  7c:	48 8d 0d b5 ff ff ff 	lea    -0x4b(%rip),%rcx        # 38 <__tcf_0>
  83:	e8 00 00 00 00       	callq  88 <_Z41__static_initialization_and_destruction_0ii+0x35>
  88:	90                   	nop
  89:	48 83 c4 20          	add    $0x20,%rsp
  8d:	5d                   	pop    %rbp
  8e:	c3                   	retq   

000000000000008f <_GLOBAL__sub_I_main>:
  8f:	55                   	push   %rbp
  90:	48 89 e5             	mov    %rsp,%rbp
  93:	48 83 ec 20          	sub    $0x20,%rsp
  97:	ba ff ff 00 00       	mov    $0xffff,%edx
  9c:	b9 01 00 00 00       	mov    $0x1,%ecx
  a1:	e8 ad ff ff ff       	callq  53 <_Z41__static_initialization_and_destruction_0ii>
  a6:	90                   	nop
  a7:	48 83 c4 20          	add    $0x20,%rsp
  ab:	5d                   	pop    %rbp
  ac:	c3                   	retq   
  ad:	90                   	nop
  ae:	90                   	nop
  af:	90                   	nop

Disassembly of section .bss:

0000000000000000 <_ZStL8__ioinit>:
	...

Disassembly of section .rdata:

0000000000000000 <_ZStL19piecewise_construct>:
	...

0000000000000001 <_ZStL13allocator_arg>:
	...

0000000000000002 <_ZStL6ignore>:
	...

0000000000000004 <_ZN9__gnu_cxxL21__default_lock_policyE>:
   4:	02 00                	add    (%rax),%al
	...

0000000000000008 <_ZStL10defer_lock>:
	...

0000000000000009 <_ZStL11try_to_lock>:
	...

000000000000000a <_ZStL10adopt_lock>:
	...

000000000000000c <_ZNSt15regex_constantsL5icaseE>:
   c:	01 00                	add    %eax,(%rax)
	...

0000000000000010 <_ZNSt15regex_constantsL6nosubsE>:
  10:	02 00                	add    (%rax),%al
	...

0000000000000014 <_ZNSt15regex_constantsL8optimizeE>:
  14:	04 00                	add    $0x0,%al
	...

0000000000000018 <_ZNSt15regex_constantsL7collateE>:
  18:	08 00                	or     %al,(%rax)
	...

000000000000001c <_ZNSt15regex_constantsL10ECMAScriptE>:
  1c:	10 00                	adc    %al,(%rax)
	...

0000000000000020 <_ZNSt15regex_constantsL5basicE>:
  20:	20 00                	and    %al,(%rax)
	...

0000000000000024 <_ZNSt15regex_constantsL8extendedE>:
  24:	40 00 00             	add    %al,(%rax)
	...

0000000000000028 <_ZNSt15regex_constantsL3awkE>:
  28:	80 00 00             	addb   $0x0,(%rax)
	...

000000000000002c <_ZNSt15regex_constantsL4grepE>:
  2c:	00 01                	add    %al,(%rcx)
	...

0000000000000030 <_ZNSt15regex_constantsL5egrepE>:
  30:	00 02                	add    %al,(%rdx)
	...

0000000000000034 <_ZNSt15regex_constantsL12__polynomialE>:
  34:	00 04 00             	add    %al,(%rax,%rax,1)
	...

0000000000000038 <_ZNSt15regex_constantsL13match_defaultE>:
  38:	00 00                	add    %al,(%rax)
	...

000000000000003c <_ZNSt15regex_constantsL13match_not_bolE>:
  3c:	01 00                	add    %eax,(%rax)
	...

0000000000000040 <_ZNSt15regex_constantsL13match_not_eolE>:
  40:	02 00                	add    (%rax),%al
	...

0000000000000044 <_ZNSt15regex_constantsL13match_not_bowE>:
  44:	04 00                	add    $0x0,%al
	...

0000000000000048 <_ZNSt15regex_constantsL13match_not_eowE>:
  48:	08 00                	or     %al,(%rax)
	...

000000000000004c <_ZNSt15regex_constantsL9match_anyE>:
  4c:	10 00                	adc    %al,(%rax)
	...

0000000000000050 <_ZNSt15regex_constantsL14match_not_nullE>:
  50:	20 00                	and    %al,(%rax)
	...

0000000000000054 <_ZNSt15regex_constantsL16match_continuousE>:
  54:	40 00 00             	add    %al,(%rax)
	...

0000000000000058 <_ZNSt15regex_constantsL16match_prev_availE>:
  58:	80 00 00             	addb   $0x0,(%rax)
	...

000000000000005c <_ZNSt15regex_constantsL14format_defaultE>:
  5c:	00 00                	add    %al,(%rax)
	...

0000000000000060 <_ZNSt15regex_constantsL10format_sedE>:
  60:	00 01                	add    %al,(%rcx)
	...

0000000000000064 <_ZNSt15regex_constantsL14format_no_copyE>:
  64:	00 02                	add    %al,(%rdx)
	...

0000000000000068 <_ZNSt15regex_constantsL17format_first_onlyE>:
  68:	00 04 00             	add    %al,(%rax,%rax,1)
	...

000000000000006c <_ZNSt15regex_constantsL13error_collateE>:
  6c:	00 00                	add    %al,(%rax)
	...

0000000000000070 <_ZNSt15regex_constantsL11error_ctypeE>:
  70:	01 00                	add    %eax,(%rax)
	...

0000000000000074 <_ZNSt15regex_constantsL12error_escapeE>:
  74:	02 00                	add    (%rax),%al
	...

0000000000000078 <_ZNSt15regex_constantsL13error_backrefE>:
  78:	03 00                	add    (%rax),%eax
	...

000000000000007c <_ZNSt15regex_constantsL11error_brackE>:
  7c:	04 00                	add    $0x0,%al
	...

0000000000000080 <_ZNSt15regex_constantsL11error_parenE>:
  80:	05 00 00 00        	add    $0x6000000,%eax

0000000000000084 <_ZNSt15regex_constantsL11error_braceE>:
  84:	06                   	(bad)  
  85:	00 00                	add    %al,(%rax)
	...

0000000000000088 <_ZNSt15regex_constantsL14error_badbraceE>:
  88:	07                   	(bad)  
  89:	00 00                	add    %al,(%rax)
	...

000000000000008c <_ZNSt15regex_constantsL11error_rangeE>:
  8c:	08 00                	or     %al,(%rax)
	...

0000000000000090 <_ZNSt15regex_constantsL11error_spaceE>:
  90:	09 00                	or     %eax,(%rax)
	...

0000000000000094 <_ZNSt15regex_constantsL15error_badrepeatE>:
  94:	0a 00                	or     (%rax),%al
	...

0000000000000098 <_ZNSt15regex_constantsL16error_complexityE>:
  98:	0b 00                	or     (%rax),%eax
	...

000000000000009c <_ZNSt15regex_constantsL11error_stackE>:
  9c:	0c 00                	or     $0x0,%al
	...

00000000000000a0 <_ZNSt8__detailL19_S_invalid_state_idE>:
  a0:	ff                   	(bad)  
  a1:	ff                   	(bad)  
  a2:	ff                   	(bad)  
  a3:	ff 48 65             	decl   0x65(%rax)
  a6:	6c                   	insb   (%dx),%es:(%rdi)
  a7:	6c                   	insb   (%dx),%es:(%rdi)
  a8:	6f                   	outsl  %ds:(%rsi),(%dx)
  a9:	2c 20                	sub    $0x20,%al
  ab:	43 2b 2b             	rex.XB sub (%r11),%ebp
  ae:	20 00                	and    %al,(%rax)

Disassembly of section .xdata:

0000000000000000 <.xdata>:
   0:	01 08                	add    %ecx,(%rax)
   2:	03 05 08 32 04 03    	add    0x3043208(%rip),%eax        # 3043210 <_ZNSt8__detailL19_S_invalid_state_idE+0x3043170>
   8:	01 50 00             	add    %edx,0x0(%rax)
   b:	00 01                	add    %al,(%rcx)
   d:	08 03                	or     %al,(%rbx)
   f:	05 08 32 04 03       	add    $0x3043208,%eax
  14:	01 50 00             	add    %edx,0x0(%rax)
  17:	00 01                	add    %al,(%rcx)
  19:	08 03                	or     %al,(%rbx)
  1b:	05 08 32 04 03       	add    $0x3043208,%eax
  20:	01 50 00             	add    %edx,0x0(%rax)
  23:	00 01                	add    %al,(%rcx)
  25:	08 03                	or     %al,(%rbx)
  27:	05 08 32 04 03       	add    $0x3043208,%eax
  2c:	01 50 00             	add    %edx,0x0(%rax)
	...

Disassembly of section .pdata:

0000000000000000 <.pdata>:
   0:	00 00                	add    %al,(%rax)
   2:	00 00                	add    %al,(%rax)
   4:	38 00                	cmp    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	00 00                	add    %al,(%rax)
   a:	00 00                	add    %al,(%rax)
   c:	38 00                	cmp    %al,(%rax)
   e:	00 00                	add    %al,(%rax)
  10:	53                   	push   %rbx
  11:	00 00                	add    %al,(%rax)
  13:	00 0c 00             	add    %cl,(%rax,%rax,1)
  16:	00 00                	add    %al,(%rax)
  18:	53                   	push   %rbx
  19:	00 00                	add    %al,(%rax)
  1b:	00 8f 00 00 00 18    	add    %cl,0x18000000(%rdi)
  21:	00 00                	add    %al,(%rax)
  23:	00 8f 00 00 00 ad    	add    %cl,-0x53000000(%rdi)
  29:	00 00                	add    %al,(%rax)
  2b:	00 24 00             	add    %ah,(%rax,%rax,1)
	...

Disassembly of section .ctors:

0000000000000000 <.ctors>:
   0:	8f 00                	popq   (%rax)
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rdata$zzz:

0000000000000000 <.rdata$zzz>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 47 4e             	sub    %al,0x4e(%rdi)
   8:	55                   	push   %rbp
   9:	29 20                	sub    %esp,(%rax)
   b:	39 2e                	cmp    %ebp,(%rsi)
   d:	32 2e                	xor    (%rsi),%ch
   f:	30 00                	xor    %al,(%rax)
	...

Disassembly of section .rdata$.refptr._ZSt4cout:

0000000000000000 <.refptr._ZSt4cout>:
	...
