#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数：统计字符数
int count_characters(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) { // 逐个读取文件字符，直到文件末尾
        count++; // 每读取一个字符，字符数加一
    }

    return count; // 返回字符数
}

// 函数：统计单词数
int count_words(FILE *file) {
    int count = 0;
    char prev = ' '; // 初始化前一个字符为空格
    char current;

    while ((current = fgetc(file)) != EOF) { // 逐个读取文件字符，直到文件末尾
        if (current == ' ' || current == ',') { // 如果当前字符为空格或逗号
            if (prev != ' ' && prev != ',' && prev != '\n' && prev != '\t') { // 前一个字符不为空格、逗号、换行符、制表符
                count++; // 单词数加一
            }
        }
        prev = current; // 更新前一个字符为当前字符
    }

    // 如果最后一个字符不是空格、逗号、换行符、制表符，则单词数加一
    if (prev != ' ' && prev != ',' && prev != '\n' && prev != '\t') {
        count++;
    }

    return count; // 返回单词数
}

int main(int argc, char *argv[]) {
    if (argc != 3) { // 参数错误检查
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // 获取参数选项
    char *filename = argv[2]; // 获取文件名

    FILE *file = fopen(filename, "r"); // 打开文件
    if (file == NULL) { // 文件打开失败检查
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file); // 统计字符数
        printf("Characters count: %d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file); // 统计单词数
        printf("Words count: %d\n", count);
    } else {
        printf("Invalid option. Please use -c or -w.\n");
        return 1;
    }

    fclose(file); // 关闭文件
    return 0;
}

