# LRU Log Samples

This folder intentionally stores selected log samples instead of the full runtime log directory.

Why these files were selected:

- `fault-crash-root-2026-05-26.txt`: small crash log with `0xc0000005`, Qt thread warning, axis communication warnings, and task/state-machine traces.
- `fault-crash-release-2026-06-07.txt`: small release crash log showing repeated UDP bind failure, light-controller timeout, and `0xc0000005` crashes.
- `normal-runtime-2026-06-24-excerpt.txt`: representative normal runtime excerpt from `release/log_2026-06-24`, selected because the full source log is large and contains normal status responses such as `ret_code=0`, empty `errors`, empty `fatals`, and PGV/localization response entries.

Large raw logs under `GuangJiSuo/LRU/release/` were not committed because this repository is not using Git LFS and several files are tens to hundreds of MB.
