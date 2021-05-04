#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int countChar(char fileName[]) {
    FILE* p = fopen(fileName, "r");
    int res = 0;
    char c;
    if (p == NULL) {
        printf("open error");
        return 0;
    }
    while ((c = fgetc(p)) != EOF)
        res++;
    fclose(p);
    return res;
}
int countWord(char fileName[]) {
    FILE* p = fopen(fileName, "r");
    int res = 0;
    if (p == NULL) {
        printf("open error");
        return 0;
    }
    char buf[102400] = { 0 };
    fread(buf, 1024, 100, p);
    int index = 0;
    while (buf[index] != '\0') {
        if (buf[index] == ' ' || buf[index] == ',')
            res++;
        index++;
    }
    fclose(p);
    return res;
}
int main() {
    char op[3];
    gets_s(op);
    char fileName[15];
    gets_s(fileName);
    int res;
    if (op[1] == 'c') {//计算字符数
        res = countChar(fileName);
        printf("字符数：%d", res);
    }
    else if (op[1] == 'w') {//计算单词数
        res = countWord(fileName);
        printf("单词数：%d", res);
    }
    return 0;
}