#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int year;
    struct Book* next;
};

struct Book* createBook(char title[], float price, int pages, char language[], float weight, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

struct Book* addBook(struct Book* head, char title[], float price, int pages, char language[], float weight, int year) {
    struct Book* newBook = createBook(title, price, pages, language, weight, year);
    if (head == NULL) {
        return newBook;
    } else {
        struct Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
        return head;
    }
}

void displayBooks(struct Book* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Book* current = head;
    int bookNumber = 1;
    while (current != NULL) {
        printf("Book %d:\n", bookNumber);
        printf("Title: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Number of Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.2f\n", current->weight);
        printf("Year of Publication: %d\n", current->year);
        printf("\n");
        current = current->next;
        bookNumber++;
    }
}

void freeBooks(struct Book* head) {
    struct Book* current = head;
    while (current != NULL) {
        struct Book* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Book* bookList = NULL;

    bookList = addBook(bookList, "Harry Potter and the Sorcerer's Stone", 15.99, 223, "English", 1.5, 1997);
    bookList = addBook(bookList, "Harry Potter and the Chamber of Secrets", 16.99, 251, "English", 1.6, 1998);
    bookList = addBook(bookList, "Harry Potter and the Prisoner of Azkaban", 18.99, 317, "English", 1.7, 1999);
    bookList = addBook(bookList, "Harry Potter and the Goblet of Fire", 20.99, 636, "English", 2.0, 2000);
    bookList = addBook(bookList, "Harry Potter and the Order of the Phoenix", 22.99, 766, "English", 2.2, 2003);
    bookList = addBook(bookList, "Harry Potter and the Half-Blood Prince", 24.99, 607, "English", 1.9, 2005);
    bookList = addBook(bookList, "Harry Potter and the Deathly Hallows", 26.99, 607, "English", 2.1, 2007);

    displayBooks(bookList);

    freeBooks(bookList);

    return 0;
}
