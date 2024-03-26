#include <stdio.h>

void writeFile(void);
void readFile(void);

int main(void) {
    writeFile();
    readFile();
}

void writeFile(void) {
    FILE *fp;
    fp = fopen("testFile", "w");
    fprintf(fp, "File Write Test\n");
    char testStr[1024] = "Test String\n";
    fwrite(testStr, 100, 1, fp);
    fclose(fp);
}

void readFile(void) {
    FILE *fp;
    char str[1024];
    fp = fopen("testFile", "r");
    fgets(str, 1024, fp);   printf("%s",str);
    fread(str, 1024, 1, fp); printf("%s\n", str);
    fclose(fp);
}
