#ifndef ERROR_H
#define ERROR_H

#ifdef __clang__
#define ERROR_OCCURRED_CALLING(func, msg) fprintf(stderr, "%s %s at %s(%d):%s\n\n", #func, (msg), __FILE_NAME__, __LINE__, __func__)
#else
#define ERROR_OCCURRED_CALLING(func, msg) fprintf(stderr, "%s %s at %s(%d):%s\n\n", #func, (msg), __FILE__, __LINE__, __func__)
#endif

#endif //ERROR_H
