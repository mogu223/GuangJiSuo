from enum import Enum
# https://www.jb51.net/article/242798.htm

class Directive(Enum):
    run_task = 1
    run_task_start = 2
    run_task_end = 9
    run_task_error = 10
    run_task_close = 15
    sync_store = 3
    run_block_start = 4
    run_block_end = 5
    run_block_warn = 12
    run_block_error = 13
    run_block_print = 14
    sync_breaks = 6
    run_pause = 7
    run_continue = 8
    ping = 11
    skip_block = 16
    skip_break = 17
    skip_block_no_excute = 18
    close_connect=19
    skip_next_block = 20
    skip_block_back=21,
    block_debug=22,
    sys_exit=23
