#include <stdio.h>
#include <stdlib.h>

// 单例结构体定义
typedef struct {
    int value;
} Singleton;

// 获取单例实例的函数
Singleton* getInstance() {
    static Singleton* instance = NULL;
    if (instance == NULL) {
        instance = (Singleton*)malloc(sizeof(Singleton));
        if (instance == NULL) {
            fprintf(stderr, "内存分配失败\n");
            exit(EXIT_FAILURE);
        }
        instance->value = 0;  // 初始化成员变量
    }
    return instance;
}

int main() {
    Singleton* s1 = getInstance();
    Singleton* s2 = getInstance();

    s1->value = 42;
    printf("s2->value = %d\n", s2->value);  // 输出 42，说明是同一个实例

    // 注意：程序结束时可以选择释放内存，但单例通常贯穿程序生命周期
    // free(s1);

    return 0;
}

