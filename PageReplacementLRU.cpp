#include <stdio.h>
#include <stdlib.h>

int main()

{

	int frames=0,pages=0,pagefault=0,k=0,q[20],count=0,copy[20],count2[20],i,r,j ;

	printf("Enter no. of pages: ");

	scanf("%d", &pages);

	printf("Enter no. of frames: ");

	scanf("%d", &frames);



	int str[pages];

	printf("Enter the number String: ");

	for (i = 0; i < pages; i++) 

	{

		scanf("%d", &str[i]);

	}



	q[k] = str[k];

	printf("\n\t%d\n",q[k]);

	pagefault++ ; 

	k++;

	

	for( i=1 ; i<pages ; i++)

	{

		count=0;

		for(j=0 ; j<frames ; j++)

		{

			if(str[i] != q[j]) //check whether page page[i]

				count++;

		}

		if( count == frames )	//replaces the page with p[i]

		{

			pagefault++;

			if( k < frames ) //no need to search for least recently used page

			{

				q[k]=str[i]; // add page p[i] to frame at k

				k++;

				for(j=0;j<k;j++) 

					//Display contents of all frames

					printf("\t%d",q[j]);

					printf("\n\n");

			}

			else // search the least recently used page for replacement

			{

				for(r=0 ;r<frames ;r++)

				{

					count2[r]=0;

					for( j=i-1 ; j<pages ; j-- )

					{

					if(q[r]!=str[j])

						count2[r]++;

					else

						break;

					}

				}

				for( r=0 ; r<frames ; r++ )

					copy[r]=count2[r]; //copy the contents of array count2 into copy

				

				int temp;	

				for(r=0 ; r<frames ; r++) // sorting

				{

					for(j=r ; j<frames ; j++)

					{

						if( copy[r]<copy[j] )	

						{

							temp = copy[r];

							copy[r]=copy[j];

							copy[j]=temp;

						}

					}

				}

				

				for( r=0 ;r<frames ;r++)

				{

					if( count2[r] == copy[0] )

						q[r]=str[i];

					printf("\t%d",q[r]);

				}

				printf("\n\n");

			}

		}

	}



	printf("The no. of page fault id %d\n ",pagefault);

	return 0;

}
