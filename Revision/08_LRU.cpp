#include <stdio.h>
int main()
{
    int q[20], p[50], c = 0, c1, f, i, j, k = 0, n, r, t, b[20], c2[20];
    // n is number of pages
    // f is number of frames  
    // c is for count number of miss or entry of new page
    // p is array of reference string
    // q is array of page string which has entered in the frame
    // c1 is signal for frame is full or not
    // t is temporary varible for swaping
    // b is the page reference string which are least recently used
    // r is the index of page which are least recently used
    // c2 array of page reference when frame is full
    printf("Enter no of pages: ");
    scanf("%d", &n);//12
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d", &f);//3
    q[k] = p[k];//storing of first page reference string 
    printf("\n\t%d\n", q[k]);//showing first page reference string
    c++;// it means that first page entered in the frame or miss
    k++;// chance of another string //k=1
    for (i = 1; i < n; i++)//start with second page (until all pages doesn't store into the frame)
    {
        c1 = 0;// initially frame1 is empty
        for (j = 0; j < f; j++)//until total frame does not be fill
        {
            if (p[i] != q[j])// if page in not in the frame or miss
                c1++;//page inserted in the frame
        }
        if (c1 == f)//frame is full
        {
            c++;//another page entered in the frame
            if (k < f)//k=1 
            {
                q[k] = p[i];// pages which are in the frame
                k++;
                for (j = 0; j < k; j++)
                    printf("\t%d", q[j]);
                printf("\n");
            }//k=3   since number of frame =3
            else
            {//lru logic
                for (r = 0; r < f; r++)//f=3
                {
                    c2[r] = 0;
                    for (j = i - 1; j < n; j--)//i=1 and n=12
                    {
                        if (q[r] != p[j])//finding the index of page which are least recently used
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];//least recently used page reference
                for (r = 0; r < f; r++)//swaping of pages using lru algorithm
                {
                    for (j = r; j < f; j++)//least recently used page number denoted by r
                    {
                        if (b[r] < b[j])
                        {
                            t = b[r];
                            b[r] = b[j]; // swapping 
                            b[j] = t;
                        }
                    }
                }
                for (r = 0; r < f; r++)
                {
                    if (c2[r] == b[0])
                        q[r] = p[i];//Now the new page has entered in the frame
                    printf("\t%d", q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("\nThe total no of page faults is %d", c);
    printf("\nThe no of page hits is %d", n-c);
}
//time complexity of the alogirithm more than O(n^3)