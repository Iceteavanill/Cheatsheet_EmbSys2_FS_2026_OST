// LIB.h
#ifndef INCLUDE_LIB_H_ // includeguards
#define INCLUDE_LIB_H_
#ifdef __cplusplus // check if c++ compiler
extern "C"{ // Wrap all code with "extern"
#endif

int libfunc(int param);
// ...
#ifdef __cplusplus
};
#endif // (#ifdef __cplusplus)
#endif // (#ifndef INCLUDE_LIB_H_)