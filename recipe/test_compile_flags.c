#include <zlib.h>

int main()
{
    // compile flags must be larger than 1 << 10 if compiled with ZLIB_WINAPI
    printf("zlib version %s = 0x%04x, compile flags = 0x%lx\n",
            ZLIB_VERSION, ZLIB_VERNUM, zlibCompileFlags());

#ifdef ZLIB_WINAPI
    if (zlibCompileFlags() < (1 << 10)) {
        exit(1);
    }
#else
    if (zlibCompileFlags() >= (1 << 10)) {
        exit(1);
    }
#endif
}
