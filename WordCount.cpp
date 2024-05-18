#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ͳ���ַ���
int count_characters(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) { // �����ȡ�ļ��ַ���ֱ���ļ�ĩβ
        count++; // ÿ��ȡһ���ַ����ַ�����һ
    }

    return count; // �����ַ���
}

// ������ͳ�Ƶ�����
int count_words(FILE *file) {
    int count = 0;
    char prev = ' '; // ��ʼ��ǰһ���ַ�Ϊ�ո�
    char current;

    while ((current = fgetc(file)) != EOF) { // �����ȡ�ļ��ַ���ֱ���ļ�ĩβ
        if (current == ' ' || current == ',') { // �����ǰ�ַ�Ϊ�ո�򶺺�
            if (prev != ' ' && prev != ',' && prev != '\n' && prev != '\t') { // ǰһ���ַ���Ϊ�ո񡢶��š����з����Ʊ��
                count++; // ��������һ
            }
        }
        prev = current; // ����ǰһ���ַ�Ϊ��ǰ�ַ�
    }

    // ������һ���ַ����ǿո񡢶��š����з����Ʊ�����򵥴�����һ
    if (prev != ' ' && prev != ',' && prev != '\n' && prev != '\t') {
        count++;
    }

    return count; // ���ص�����
}

int main(int argc, char *argv[]) {
    if (argc != 3) { // ����������
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // ��ȡ����ѡ��
    char *filename = argv[2]; // ��ȡ�ļ���

    FILE *file = fopen(filename, "r"); // ���ļ�
    if (file == NULL) { // �ļ���ʧ�ܼ��
        printf("Error opening file.\n");
        return 1;
    }

    int count = 0;
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file); // ͳ���ַ���
        printf("Characters count: %d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file); // ͳ�Ƶ�����
        printf("Words count: %d\n", count);
    } else {
        printf("Invalid option. Please use -c or -w.\n");
        return 1;
    }

    fclose(file); // �ر��ļ�
    return 0;
}

