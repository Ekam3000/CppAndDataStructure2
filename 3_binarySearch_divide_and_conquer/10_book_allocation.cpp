// you are given number of pages in n differnt books and m students . the books are arranged in acending order of number of pages. every student is assigned to read some consecutive books. the task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
// 4 2
// 12 34 67 90

#include<iostream>
using namespace std;
// no student should be assigned to readmore than mid pages
bool max_pages(int * books , int n, int mid, int m)
{
    int count=1;
    int max_pages=0;
    for(int i=0; i<n; i++)
    {
     if((max_pages+books[i])<=mid)
     {
     max_pages +=books[i];
     }
     else{
        count++;

            if (books[i] > mid || count > m)
            {
                return false;
            }
        max_pages=0;
        i--;
     }
    }
    if(count==m)
    return true;
    else
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int books[n];
    for(int i=0;i<n;i++)
    {
        cin>>books[i];
    }
    int s=0;
    s=40;// s=40 more true becoz student will be reading atleast one book and will read 40 pages.
    int e=0;
    for(int i=0;i<n;i++)
    {
        e+=books[i];
    }
    int ans=-1;
    int mid;
    while(s<=e)
    {

        mid=(s+e)/2;
        bool c= max_pages(books,n,mid,m);
        if(c)
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*
#include <iostream>
using namespace std;
bool possibleSolution(int a[], int size, int students, int mid)
{
    int studentcount = 1;
    int pagecount = 0;
    for (int i = 0; i < size; i++)
    {
        if ((pagecount + a[i]) <= mid)
        {
            pagecount = pagecount + a[i];
        }
        else
        {
            studentcount++;
            if (a[i] > mid || studentcount > students)
            {
                return false;
            }
            pagecount = a[i];
        }
        if (studentcount > students)
        {
            return false;
        }
    }
    return true;
}
int BookAllocation(int a[], int size, int students)
{
    int start = 0;
    int end, sum = 0;
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
    }
    end = sum;

    while (start <= end)
    {
        int mid = start + (end - mid) / 2;
        if (possibleSolution(a, size, students, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {10, 20, 30, 40};
    int students;
    cout << "Enter the no of students";
    cin >> students;
    int ans = BookAllocation(a, 4, students);
    cout << ans << endl;
    return 0;
}
*/
// if minimize the max ans, then condition true hone par end ko less karo
// if miximize the min ans, then condition true hone par start ko less karo