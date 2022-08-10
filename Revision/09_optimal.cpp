#include <stdio.h>
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: "); // taking the number of process
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: "); // taking the number of pages
    scanf("%d", &no_of_pages);

    printf("Enter page reference string: ");

    for (i = 0; i < no_of_pages; ++i)
    { // taking reference number
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i)
    {                   // setting all frame value -1
        frames[i] = -1; //-1 means frame is empty
    }
    // optimal algorithm
    for (i = 0; i < no_of_pages; ++i)// no of page=12
    { 
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)// no of frames=3
        { 
            if (frames[j] == pages[i])//hit
            { 
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)//no of frame = 3
            {
                if (frames[j] == -1) // if frame is empty
                {                        
                    faults++;             // page faults
                    frames[j] = pages[i]; // putting that page into the frame
                    flag2 = 1;
                    break;
                }
            }
        }
//main logic
        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)//no of frame = 3
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)//no of page = 12
                {
                    if (frames[j] == pages[k])//comparing with frame value and next upcoming page value
                    {
                        temp[j] = k;//storing that position in the temp
                        break;
                    }
                }
            }

            for (j = 0; j < no_of_frames; ++j)//no of frame=3
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];//replace
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}