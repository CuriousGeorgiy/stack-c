#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H

#define FREE(ptr) do {              \
                      free(ptr);    \
                      (ptr) = NULL; \
                  } while (0)

#endif /* MEMORY_ALLOC_H */
