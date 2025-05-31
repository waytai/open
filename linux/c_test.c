#include <stdio.h>
#include <stdlib.h>

typedef void (*TestFunc)(void);

typedef struct TestCase {
    const char* name;
    TestFunc func;
    struct TestCase* next;
} TestCase;

static TestCase* test_list = NULL;
static int tests_run = 0;
static int tests_failed = 0;

// 注册测试用例
void register_test(const char* name, TestFunc func) {
    TestCase* test = (TestCase*)malloc(sizeof(TestCase));
    test->name = name;
    test->func = func;
    test->next = test_list;
    test_list = test;
}

// 断言宏
#define ASSERT(expr) \
    do { \
        if (!(expr)) { \
            printf("  [FAILED] %s:%d: Assertion `%s` failed.\n", __FILE__, __LINE__, #expr); \
            tests_failed++; \
            return; \
        } \
    } while(0)

// 运行所有测试
void run_all_tests() {
    printf("Running tests...\n");
    TestCase* current = test_list;
    while (current) {
        printf("Test %s: ", current->name);
        current->func();
        if (tests_failed == 0) {
            printf("[PASSED]\n");
        }
        tests_run++;
        current = current->next;
    }
    printf("\nTests run: %d, Failures: %d\n", tests_run, tests_failed);
}

// 测试用例示例
void test_addition() {
    int a = 2 + 3;
    ASSERT(a == 5);
}

void test_subtraction() {
    int a = 5 - 3;
    ASSERT(a == 2);
}

void test_failure() {
    int a = 1;
    ASSERT(a == 0);  // 故意失败
}

int main() {
    register_test("Addition", test_addition);
    register_test("Subtraction", test_subtraction);
    register_test("FailureTest", test_failure);
    while(test_list != NULL){
        TestCase* temp = test_list;
        printf("name is %s\r\n", temp->name);
        test_list = test_list->next;
        free(temp);
    }

    run_all_tests();

    return tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

