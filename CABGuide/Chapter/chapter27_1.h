// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter27_1
// File chapter27_1.h

/* This header file defines a structure for information about a book */

struct bookInfo {
    char title[40];
    char author[25];
    float price;
    int pages;
};
