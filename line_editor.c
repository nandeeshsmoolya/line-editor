#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 200

char lines[MAX_LINES][MAX_LEN];
int lineCount = 0;

void display() {
    if (lineCount == 0) {
        printf("Document is empty.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
        printf("%d: %s", i + 1, lines[i]);
}

void insertLine() {
    int pos;

    printf("Enter line number: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > lineCount + 1 || lineCount >= MAX_LINES) {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = lineCount; i >= pos; i--)
        strcpy(lines[i], lines[i - 1]);

    printf("Enter text: ");
    fgets(lines[pos - 1], MAX_LEN, stdin);

    lineCount++;
    printf("Line inserted.\n");
}

void deleteLine() {
    int pos;

    printf("Enter line number: ");
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > lineCount) {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = pos - 1; i < lineCount - 1; i++)
        strcpy(lines[i], lines[i + 1]);

    lineCount--;
    printf("Line deleted.\n");
}

void saveFile() {
    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
        fputs(lines[i], fp);

    fclose(fp);
    printf("File saved.\n");
}

void loadFile() {
    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    lineCount = 0;

    while (lineCount < MAX_LINES &&
           fgets(lines[lineCount], MAX_LEN, fp) != NULL) {
        lineCount++;
    }

    fclose(fp);
    printf("File loaded.\n");
}

void searchText() {
    char word[100];
    int found = 0;

    printf("Enter word or phrase: ");
    getchar();
    fgets(word, sizeof(word), stdin);

    word[strcspn(word, "\n")] = '\0';

    for (int i = 0; i < lineCount; i++) {
        if (strstr(lines[i], word) != NULL) {
            printf("Found on line %d: %s", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
        printf("Text not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SIMPLE LINE EDITOR =====\n");
        printf("1. Insert line\n");
        printf("2. Delete line\n");
        printf("3. Display document\n");
        printf("4. Save file\n");
        printf("5. Load file\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: insertLine(); break;
            case 2: deleteLine(); break;
            case 3: display(); break;
            case 4: saveFile(); break;
            case 5: loadFile(); break;
            case 6: searchText(); break;
            case 7:
                printf("Exiting editor...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}