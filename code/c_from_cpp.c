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
\end{lstlisting}
\end{minipage}
\begin{minipage}[t]{0.5\columnwidth}
\begin{lstlisting}
// LIB.c
# include "LIB.h"
int libfunc(int param){
    return param & 1;
}