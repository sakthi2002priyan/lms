#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int year;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int count;
};

void addBook(struct Library* library) {
    if (library->count >= MAX_BOOKS) {
        printf("The library is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    printf("Enter the author of the book: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);

    library->books[library->count] = newBook;
    library->count++;
    printf("Book added successfully.\n");
}

void searchBook(struct Library* library, const char* title) {
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s", library->books[i].title);
            printf("Author: %s", library->books[i].author);
            printf("Year: %d\n", library->books[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void displayBooks(struct Library* library) {
    printf("Library Books:\n");
    for (int i = 0; i < library->count; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s", library->books[i].title);
        printf("Author: %s", library->books[i].author);
        printf("Year: %d\n", library->books[i].year);
    }
}

void deleteBook(struct Library* library, const char* title) {
    int found = 0;
    for (int i = 0; i < library->count; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            for (int j = i; j < library->count - 1; j++) {
                library->books[j] = library->books[j + 1];
            }
            library->count--;
            printf("Book deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    struct Library library;
    library.count = 0;

    int choice;
    char title[100];
    printf("Library Management System\n");

    do {
        printf("\n1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display All Books\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                printf("Enter the title of the book to search: ");
                fgets(title, sizeof(title), stdin);
                searchBook(&library, title);
                break;
            case 3:
                displayBooks(&library);
                break;
            case 4:
                printf("Enter the title of the book to delete: ");
                fgets(title, sizeof(title), stdin);
                deleteBook(&library, title);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}