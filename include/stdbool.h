#ifndef __STDBOOL_H
#define __STDBOOL_H

/* Don't define bool, true, and false in C++ */
#ifndef __cplusplus
#define bool _Bool
#define true 1
#define false 0
#endif

#define __bool_true_false_are_defined 1

#endif /* __STDBOOL_H */
