/*
2) Write a modular C program to store N number of book details using structures and implement the following functions.
a) Read and Display book details.
b) Sort the book details using ISBN number.
c) Search book by ISBN number and display the details.
*/

#include<stdio.h>

typedef struct book
{
    char title[20], author[20];
    int isbn;
    float price;
}B;

void read(B books[10], int n)
{
    int i;
    printf("Enter book title, author, isbn and price\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %f", books[i].title, books[i].author, &books[i].isbn, &books[i].price);
    }
}

void display(B books[10], int n)
{
    int i;
    printf("\nBooks Details\n");
    printf("Title\t\tAuthor\tIsbn\tprice\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%s\t%d\t%0.2f\n",books[i].title, books[i].author,books[i].isbn,books[i].price);
    }
}

void bubble_sort_books(B books[10], int n)
{
    int i,j;
    B temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1-i); j++)
        {
            if(books[j].isbn > books[j+1].isbn)
            {
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void search_book(B books[10], int n, int search_isbn)
{
    int i, status=0,index;
    for(i=0;i<n;i++)
    {
        if(books[i].isbn == search_isbn)
        {
            status=1;
            index=i;
            break;
        }
    }
    if(status==1)
    {
        printf("Search Successfull. Book Details are: \n");
        printf("Title\t\tAuthor\tIsbn\tprice\n");
         printf("%s\t\t%s\t%d\t%0.2f\n",books[index].title, books[index].author,books[index].isbn,books[index].price);
    }
    else
        printf("Search Unsuccessfull. Book Details not found.\n");
}

int main()
{
    B books[10];
    int n, search_isbn;
    printf("Enter number of books details to read\n");
    scanf("%d",&n);
    read(books,n);
    printf("Books Details before sorting\n");
    display(books,n);
    bubble_sort_books(books, n);
    printf("Books Details after sorting\n");
    display(books,n);
    printf("Enter isbn to search a book\n");
    scanf("%d",&search_isbn);
    search_book(books, n, search_isbn);
    return 0;
}
