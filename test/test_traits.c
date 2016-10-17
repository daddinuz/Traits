#include "traits.h"


TEST(BOOL) {
    ASSERT(0 != 1);
    ASSERT_TRUE(true);
    ASSERT_FALSE(false);
}

TEST(PTR) {
    ASSERT_PTR_EQUAL(NULL, NULL);
    ASSERT_PTR_NOT_EQUAL(NULL, (void *) 1);
    ASSERT_PTR_NULL(NULL);
    ASSERT_PTR_NOT_NULL((void *) 1);
}

TEST(STR) {
    ASSERT_STR_EQUAL("Hello", "Hello");
    ASSERT_STR_NOT_EQUAL("Hello", "World");
}

#define NUMERICAL(_Type, _Identifier)                                               \
    TEST(_Identifier) {                                                             \
        ASSERT_##_Identifier##_EQUAL            ((_Type)0, (_Type)0);               \
        ASSERT_##_Identifier##_NOT_EQUAL        ((_Type)1, (_Type)0);               \
        ASSERT_##_Identifier##_GREATER_EQUAL    ((_Type)1, (_Type)1);               \
        ASSERT_##_Identifier##_GREATER          ((_Type)0, (_Type)1);               \
        ASSERT_##_Identifier##_LESS_EQUAL       ((_Type)0, (_Type)0);               \
        ASSERT_##_Identifier##_LESS             ((_Type)1, (_Type)0);               \
        ASSERT_##_Identifier##_WITHIN           ((_Type)5, (_Type)10, (_Type)5);    \
        ASSERT_##_Identifier##_WITHIN           ((_Type)5, (_Type)10, (_Type)10);   \
        ASSERT_##_Identifier##_WITHIN           ((_Type)5, (_Type)10, (_Type)15);   \
    }

/*
 * Integer
 */
NUMERICAL(unsigned, UINT)
NUMERICAL(uint8_t , UINT8)
NUMERICAL(uint16_t, UINT16)
NUMERICAL(uint32_t, UINT32)
NUMERICAL(size_t, SIZE)
NUMERICAL(int, INT)
NUMERICAL(int8_t , INT8)
NUMERICAL(int16_t, INT16)
NUMERICAL(int32_t, INT32)

#ifdef SUPPORT_64BIT
NUMERICAL(uint64_t, UINT64)
NUMERICAL(int64_t, INT64)
#endif

/*
 * Floating
 */
NUMERICAL(float, FLOAT)
NUMERICAL(double, DOUBLE)

/*
 *
 */
int main() {
    stream(stdout);

    /* Boolean   */
    message("Boolean\n");
    run(BOOL);

    /* Pointers */
    message("Pointers\n");
    run(PTR);

    /* String */
    message("String\n");
    run(STR);

    /* Integers */
    message("Integers\n");
    run(UINT);
    run(UINT8);
    run(UINT16);
    run(UINT32);
    run(SIZE);
    run(INT);
    run(INT8);
    run(INT16);
    run(INT32);

#ifdef SUPPORT_64BIT
    info("64 bits support detected\n");
    run(UINT64);
    run(INT64);
#else
    warn("64 bits support detected\n");
    run(UINT64);
    run(INT64);
#endif

    /* Floating */
    message("Floating\n");
    run(FLOAT);
    run(DOUBLE);

    return report();
}