// Source - https://stackoverflow.com/a/2744206
// Posted by Michael Aaron Safyan, modified by community. See post 'Timeline' for change history
// Retrieved 2026-06-30, License - CC BY-SA 4.0

// *.cpp file
mylibrary_mytype_t mylibrary_mytype_init() {
  return new MyType;
}

void mylibrary_mytype_destroy(mylibrary_mytype_t untyped_ptr) {
   MyType* typed_ptr = static_cast<MyType*>(untyped_ptr);
   delete typed_ptr;
}

void mylibrary_mytype_doit(mylibrary_mytype_t untyped_self, int param) {
   MyType* typed_self = static_cast<MyType*>(untyped_self);
   typed_self->doIt(param);
}