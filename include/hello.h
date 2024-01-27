#ifndef HELLO_H
#define HELLO_H

#ifdef __cplusplus
extern "C" {
#endif

// void hello();
__declspec(dllexport) void hello();

#ifdef __cplusplus
} // extern "C"
#endif

#endif
