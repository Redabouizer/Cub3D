==483376== Memcheck, a memory error detector
==483376== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==483376== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==483376== Command: ./cub3d_bonus bonus/maps/test.cub
==483376== 
==483376== 
==483376== HEAP SUMMARY:
==483376==     in use at exit: 105,075 bytes in 174 blocks
==483376==   total heap usage: 1,718 allocs, 1,544 frees, 1,210,571 bytes allocated
==483376== 

==483376== 

==483376== 8 bytes in 1 blocks are still reachable in loss record 3 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x4874B34: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x48769DF: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x487B9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x116523: mlx_int_deal_shm (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x1167A1: mlx_init (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x115A27: setup_data (setuping.c:9)
==483376==    by 0x111637: play_rey (ft_check.c:55)
==483376==    by 0x1118A6: validate_map (ft_check.c:83)
==483376==    by 0x113B03: main (main.c:34)
==483376== 

==483376== 
==483376== 16 bytes in 1 blocks are still reachable in loss record 5 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x111BE3: init_map (ft_node.c:19)
==483376==    by 0x1128DC: parse_map_file (ft_map.c:85)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 16 bytes in 1 blocks are still reachable in loss record 6 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11130F: my_malloc (mem.c:20)
==483376==    by 0x111D00: add_map_line (ft_node.c:46)
==483376==    by 0x112671: process_metadata_line (ft_data.c:69)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 16 bytes in 1 blocks are still reachable in loss record 7 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x111D00: add_map_line (ft_node.c:46)
==483376==    by 0x112671: process_metadata_line (ft_data.c:69)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 16 bytes in 1 blocks are still reachable in loss record 8 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x111D94: add_map_line (ft_node.c:55)
==483376==    by 0x112671: process_metadata_line (ft_data.c:69)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 16 bytes in 1 blocks are still reachable in loss record 9 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x112740: finalize_map (ft_map.c:39)
==483376==    by 0x1128A1: process_map_lines (ft_map.c:76)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 

==483376== 

==483376== 

==483376== 
==483376== 24 bytes in 1 blocks are still reachable in loss record 13 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x4B5458E: strdup (strdup.c:42)
==483376==    by 0x48B19AE: XInitExtension (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x4876820: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x487650A: ??? (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x48769C8: XextAddDisplay (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x487B9E2: XShmQueryVersion (in /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0)
==483376==    by 0x116523: mlx_int_deal_shm (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x1167A1: mlx_init (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x115A27: setup_data (setuping.c:9)
==483376==    by 0x111637: play_rey (ft_check.c:55)
==483376==    by 0x1118A6: validate_map (ft_check.c:83)
==483376== 

==483376== 

==483376== 
==483376== 28 bytes in 1 blocks are still reachable in loss record 16 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x110CF7: ft_calloc (ft_calloc.c:21)
==483376==    by 0x110C4B: ft_substr (ft_substr.c:27)
==483376==    by 0x110BC5: ft_strtrim (ft_strtrim.c:29)
==483376==    by 0x111B3C: set_texture (ft_check_pro.c:80)
==483376==    by 0x112510: process_metadata (ft_data.c:48)
==483376==    by 0x11261D: process_metadata_line (ft_data.c:64)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 28 bytes in 1 blocks are still reachable in loss record 17 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x110CF7: ft_calloc (ft_calloc.c:21)
==483376==    by 0x110C4B: ft_substr (ft_substr.c:27)
==483376==    by 0x110BC5: ft_strtrim (ft_strtrim.c:29)
==483376==    by 0x111B3C: set_texture (ft_check_pro.c:80)
==483376==    by 0x112548: process_metadata (ft_data.c:50)
==483376==    by 0x11261D: process_metadata_line (ft_data.c:64)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 29 bytes in 1 blocks are still reachable in loss record 18 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x110CF7: ft_calloc (ft_calloc.c:21)
==483376==    by 0x110C4B: ft_substr (ft_substr.c:27)
==483376==    by 0x110BC5: ft_strtrim (ft_strtrim.c:29)
==483376==    by 0x111B3C: set_texture (ft_check_pro.c:80)
==483376==    by 0x1124A0: process_metadata (ft_data.c:44)
==483376==    by 0x11261D: process_metadata_line (ft_data.c:64)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 29 bytes in 1 blocks are still reachable in loss record 19 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x110CF7: ft_calloc (ft_calloc.c:21)
==483376==    by 0x110C4B: ft_substr (ft_substr.c:27)
==483376==    by 0x110BC5: ft_strtrim (ft_strtrim.c:29)
==483376==    by 0x111B3C: set_texture (ft_check_pro.c:80)
==483376==    by 0x1124D8: process_metadata (ft_data.c:46)
==483376==    by 0x11261D: process_metadata_line (ft_data.c:64)
==483376==    by 0x1130A3: process_line (ft_process.c:126)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 

==483376== 
==483376== 88 bytes in 1 blocks are still reachable in loss record 32 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11130F: my_malloc (mem.c:20)
==483376==    by 0x111BE3: init_map (ft_node.c:19)
==483376==    by 0x1128DC: parse_map_file (ft_map.c:85)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 88 bytes in 1 blocks are still reachable in loss record 33 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11130F: my_malloc (mem.c:20)
==483376==    by 0x112740: finalize_map (ft_map.c:39)
==483376==    by 0x1128A1: process_map_lines (ft_map.c:76)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 

==483376== 144 bytes in 9 blocks are still reachable in loss record 42 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x111D00: add_map_line (ft_node.c:46)
==483376==    by 0x1130D5: process_line (ft_process.c:129)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 144 bytes in 9 blocks are still reachable in loss record 43 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x111D94: add_map_line (ft_node.c:55)
==483376==    by 0x1130D5: process_line (ft_process.c:129)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 149 bytes in 1 blocks are still reachable in loss record 44 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x48B5710: XOpenDisplay (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x1166E7: mlx_init (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x115A27: setup_data (setuping.c:9)
==483376==    by 0x111637: play_rey (ft_check.c:55)
==483376==    by 0x1118A6: validate_map (ft_check.c:83)
==483376==    by 0x113B03: main (main.c:34)
==483376== 

==483376== 
==483376== 160 bytes in 10 blocks are still reachable in loss record 47 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11133C: my_malloc (mem.c:26)
==483376==    by 0x112AA7: pad_map_line (ft_player.c:50)
==483376==    by 0x11277C: finalize_map (ft_map.c:45)
==483376==    by 0x1128A1: process_map_lines (ft_map.c:76)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 


==483376== 
==483376== 280 bytes in 10 blocks are still reachable in loss record 54 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11130F: my_malloc (mem.c:20)
==483376==    by 0x112AA7: pad_map_line (ft_player.c:50)
==483376==    by 0x11277C: finalize_map (ft_map.c:45)
==483376==    by 0x1128A1: process_map_lines (ft_map.c:76)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 344 bytes in 6 blocks are still reachable in loss record 55 of 70
==483376==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x49128F5: _XkbReadGetMapReply (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x491341E: XkbGetUpdatedMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x49134F4: XkbGetMap (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x4913542: ??? (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x49138AF: XkbKeycodeToKeysym (in /usr/lib/x86_64-linux-gnu/libX11.so.6.4.0)
==483376==    by 0x118287: mlx_int_param_KeyPress (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x116AE5: mlx_loop (in /home/rbouizer/Desktop/Cub3D/cub3d_bonus)
==483376==    by 0x111802: play_rey (ft_check.c:69)
==483376==    by 0x1118A6: validate_map (ft_check.c:83)
==483376==    by 0x113B03: main (main.c:34)
==483376== 
==483376== 416 bytes in 8 blocks are still reachable in loss record 56 of 70
==483376==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==483376==    by 0x11130F: my_malloc (mem.c:20)
==483376==    by 0x111D00: add_map_line (ft_node.c:46)
==483376==    by 0x1130D5: process_line (ft_process.c:129)
==483376==    by 0x112839: process_map_lines (ft_map.c:70)
==483376==    by 0x11292E: parse_map_file (ft_map.c:91)
==483376==    by 0x111888: validate_map (ft_check.c:80)
==483376==    by 0x113B03: main (main.c:34)
==483376== 


==483376== LEAK SUMMARY:
==483376==    definitely lost: 0 bytes in 0 blocks
==483376==    indirectly lost: 0 bytes in 0 blocks
==483376==      possibly lost: 0 bytes in 0 blocks
==483376==    still reachable: 105,075 bytes in 174 blocks
==483376==         suppressed: 0 bytes in 0 blocks
==483376== 
==483376== For lists of detected and suppressed errors, rerun with: -s
==483376== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 1 from 1)
