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