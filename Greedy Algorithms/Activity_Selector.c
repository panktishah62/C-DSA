#include<stdio.h>
#include<stdlib.h>


int greedy_activity_selection(int s[],int f[],int activity[],int n)
{
    for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[i]>s[j])
			{

				int k=s[i];
				s[i]=s[j];
				s[j]=k;

				int m=f[i];
				f[i]=f[j];
				f[j]=m;

				int l=activity[i];
				activity[i]=activity[j];
				activity[j]=l;

			}
		}
	}

	int i=0,count=0,prev=0;
	while(i<n)
    {
        if(s[i]>=prev)
        {
            while(f[i]==f[i+1])
            {
                i++;
            }
            printf("activity number: %d\n",activity[i]);
            count++;
            prev=f[i];
        }
        i++;
    }
    return count;


}


int main()
{
    printf("enter the number of activities\n");
    int n;
    scanf("%d",&n);
    int s[n],f[n],activity[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the starting time\n");
        scanf("%d",&s[i]);
        printf("enter the finishing time\n");
        scanf("%d",&f[i]);
        printf("enter the activity number\n");
        scanf("%d",&activity[i]);
        if(s[i]>=f[i])
        {
            printf("starting time is greater or equal to finishing time\nenter again\n");
            i--;
        }
    }

    int num_of_activities=greedy_activity_selection(s,f,activity,n);
    printf("number of activities = %d",num_of_activities);
}
