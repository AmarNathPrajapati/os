#include <iostream>
#include <stdio.h>
int main()
{
    int i, j, n, a[50], frame[10], no, k, avail, count = 0;
    // n is number of pages
    // a is array of page no.and
    // no is number of frame 
    printf("\n ENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n); // taking number of pages
    printf("\n ENTER THE PAGE NUMBER :  ");
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]); // taking page reference number
    printf("\n ENTER THE NUMBER OF FRAMES : ");
    scanf("%d", &no); // number of frames
    for (i = 0; i < no; i++)
        frame[i] = -1;//empty frame
    j = 0;
    printf("\tref string\t page frames\n");
    //fifo logic
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);//printing page number
        avail = 0;//if pages are not in the frame
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])//condition for hit
                avail = 1;//pages are in the frame
        if (avail == 0)
        {
            frame[j] = a[i];//here page are going into the frame
            j = (j + 1) % no;//swaping of page according to which came first
            count++;//replacing of one page and also it is value of page fault
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);//printing page value which are in frame
        }
        printf("\n");
    }
    printf("Page Fault Is %d", count);
    return 0;
}