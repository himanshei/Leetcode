class Solution {
public:
    int count=0;
    int countArrangement(int n) {  //n=3
        vector<int>arr(n,0);       //arr=[1,2,3]
        for(int i=0;i<n;i++) arr[i]=i+1;  //assigning the elememts in the array using n since indexeing start from 0 plus 1 is there
        check(arr,0);    //function checking for the array's beautiful arrangements
        return count;    //returning count of beautiful arrangements found in the array
    }
    void check(vector<int>& arr,int j){     //j is used for iteration over the array
        if(j==arr.size()) count++;          //when the index iteration reaches to the end means all the elements satisfied the beautiful arrangement check then increasing the count 
        for(int i=j;i<arr.size();i++){
            swap(arr,i,j);                  //swaping for more possible arrangements and checking for every arrangement
              
           if((arr[j]%(j+1)==0) ||((j+1)%(arr[j])==0)){     //checking for beautiful arrangemnt i.e. [1,2,3] so the 1st index's element % 1 should be zero and 2nd index's element % 2==0 
               check(arr,j+1);            //incrementing to the next index and checking for it's arrangement whether beautiful or not
           }
           swap(arr,i,j);                //swaping back inorder to backtrack and check for further new arrangemnts
        }
    }
void swap(vector<int>&arr,int i, int j){  //conventional swaping  to swap the elements of the array
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
    
};