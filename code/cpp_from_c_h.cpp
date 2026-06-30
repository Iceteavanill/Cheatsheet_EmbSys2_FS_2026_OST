// Source - https://stackoverflow.com/a/2744206
// Posted by Michael Aaron Safyan, modified by community. See post 'Timeline' for change history
// Retrieved 2026-06-30, License - CC BY-SA 4.0

// *.h file
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

typedef void* mylibrary_mytype_t;
EXTERNC mylibrary_mytype_t mylibrary_mytype_init();
EXTERNC void mylibrary_mytype_destroy(mylibrary_mytype_t mytype);
EXTERNC void mylibrary_mytype_doit(mylibrary_mytype_t self, int param);
#undef EXTERNC