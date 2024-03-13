rsta2-circle-playground
=======================
### Notes
- remove the code below in `circle/configure` (OS issue)
    ```bash
    if [ ! -x "`which $CC 2> /dev/null`" ]
    then
        echo "Error: Invalid toolchain prefix: ${PREFIX}" >&2
        exit 1
    fi
    ```
- `#define SCREEN_HEADLESS` in `include\circle\sysconfig.h` must be uncommented before compiling circle
- no UART enable is needed because GPIO 14 and 15 is enabled by default
    - nothing should be added to `config.txt`
- in the SD card there should be a file names `cmdline.txt` with cotent:
    - `logdev=ttyS1`

### Docs
- [circle/doc/cmdline.txt at master · rsta2/circle](https://github.com/rsta2/circle/blob/master/doc/cmdline.txt)
### issues
- https://github.com/rsta2/circle/issues/262
