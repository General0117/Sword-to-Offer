#include<iostream>
#include<vector>
using namespace std;

//int InversePairs(const vector<int>& v)
//{
//    int count=0;
//    int i,j;
//    for(i=0;i<v.size();++i)
//    {
//        for(j=i;j<v.size();++j)
//        {
//            if(v[i]>v[j])
//                count++;
//        }
//    }
//    return count;
//}

void Merge(vector<int>& v,int left,int mid,int right,vector<int>& tmp,int& count)
{
    int i=mid,j=right,k=right;
    while(i>=left && j>mid)
    {
        if(v[i]<v[j])
            tmp[k--]=v[j--];
        else
        {
            tmp[k--]=v[i--];
            count+=(j-mid);
        }
    }
    while(i>=left)
        tmp[k--]=v[i--];
    while(j>mid)
        tmp[k--]=v[j--];
    for(i=left;i<=right;++i)
    {
        v[i]=tmp[i];
    }
}

void MergeSort(vector<int>& v,int left,int right,vector<int>& tmp,int& count)
{
    if(right-left>1)
    {
        int mid=left+(right-left)/2;
        MergeSort(v,left,mid,tmp,count);
        MergeSort(v,mid+1,right,tmp,count);
        Merge(v,left,mid,right,tmp,count);
    }
    else
    {
        Merge(v,left,left,right,tmp,count);
    }
}

int InversePairs(vector<int> v)
{
    int count=0;
    vector<int> tmp;
    tmp.resize(v.size());
    MergeSort(v,0,v.size()-1,tmp,count);
    return count;
}

//------测试代码-----
void test()
{
    vector<int> v[6];
    int arr0[]={7,5,6,4};
    int arr1[]={1,2,3,4,5,6,7,8,9};
    int arr2[]={9,8,7,6,5,4,3,2,1};
    int arr3[]={5,6};
    int arr4[]={6,5};
    int arr5[]={5};
    int i,j;
    for(i=0;i<6;++i)
    {
        switch(i)
        {
            case 0:
                for(j=0;j<sizeof(arr0)/sizeof(arr0[0]);++j)
                    v[i].push_back(arr0[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            case 1:
                for(j=0;j<sizeof(arr1)/sizeof(arr1[0]);++j)
                    v[i].push_back(arr1[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            case 2:
                for(j=0;j<sizeof(arr2)/sizeof(arr2[0]);++j)
                    v[i].push_back(arr2[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            case 3:
                for(j=0;j<sizeof(arr3)/sizeof(arr3[0]);++j)
                    v[i].push_back(arr3[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            case 4:
                for(j=0;j<sizeof(arr4)/sizeof(arr4[0]);++j)
                    v[i].push_back(arr4[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            case 5:
                for(j=0;j<sizeof(arr5)/sizeof(arr5[0]);++j)
                    v[i].push_back(arr5[j]);
                cout<<InversePairs(v[i])<<endl;
                break;
            default:
                break;
        }
    }
}

int main()
{
    test();
    return 0;
}
